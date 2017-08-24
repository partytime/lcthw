#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_DATA 512
#define MAX_ROWS 100


struct Address {
    int id;
    int set;
    char name[MAX_DATA];
    char email[MAX_DATA];
    // Add a new field
    char city[MAX_DATA];
};

struct Database {
    struct Address rows[MAX_ROWS];
};

struct Connection {
    FILE *file;
    struct Database *db;
};

// fix die method to close the db
// need to define it first!
// refactor all calls to die with the correct number of options
// dont forget you can pass NULL if theres no conn
void Database_close(struct Connection *conn);

void die(const char *message, struct Connection *conn)
{
    if (errno) {
        perror(message);
    } else {
        printf("ERROR: %s\n", message);
    }
    Database_close(conn);

    exit(1);
}

void Address_print(struct Address *addr)
{
    printf("%d %s %s %s \n", addr->id, addr->name, addr->email, addr->city);
}

void Database_load(struct Connection *conn)
{
    int rc = fread(conn->db, sizeof(struct Database), 1, conn->file);
    if (rc != 1) 
        die("failed to load database.", conn);
}

struct Connection *Database_open(const char *filename, char mode)
{
    struct Connection *conn = malloc(sizeof(struct Connection));
    if (!conn)
        die("Memory error", conn);

    conn->db = malloc(sizeof(struct Database));
    if (!conn->db)
        die("memory error", conn);

    if (mode =='c') {
        conn->file = fopen(filename, "w");
    } else { 
        conn->file = fopen(filename, "r+");

        if (conn->file) {
            Database_load(conn);
        }
    }

    if (!conn->file)
        die("Failed to open the file", conn);

    return conn;
}

void Database_close(struct Connection *conn)
{
    if (conn) {
        if (conn->file)
            fclose(conn->file);
        if (conn->db)
            free(conn->db);
        free(conn);
    }
}

void Database_write(struct Connection *conn)
{
    rewind(conn->file);

    int rc = fwrite(conn->db, sizeof(struct Database), 1, conn->file);
    if (rc != 1)
        die("failed to write database.", conn);

    rc = fflush(conn->file);
    if (rc == -1)
        die("cannot flush database", conn);
}

void Database_create(struct Connection *conn)
{
    int i = 0;

    for (i = 0; i < MAX_ROWS; i++) {
        // make a prototype to initialize it
        struct Address addr = { .id = i, .set = 0 };
        // then just assign it
        conn->db->rows[i] = addr;
    }
}

void Database_set(struct Connection *conn, int id, const char *name, const char *email, const char *city)
{
    struct Address *addr = &conn->db->rows[id];
    if (addr->set)
        die("Already set, dlete it first", conn);

    addr->set = 1;

    // WARNING: bug, read the "how to break it" and fix this
    char *res = strncpy(addr->name, name, MAX_DATA);
    // fix strncpy to force '\0' as final character
    addr->name[MAX_DATA -1] = '\0';
    // demonstrate the strncpy bug
    if (!res)
        die("Name copy failed", conn);

    res = strncpy(addr->email, email, MAX_DATA);
    if (!res)
        die("email copy failed", conn);

    res = strncpy(addr->city, city, MAX_DATA);
    if (!res)
        die("city copy failed", conn);
}

void Database_get(struct Connection *conn, int id)
{
    struct Address *addr = &conn->db->rows[id];

    if (addr->set) {
        Address_print(addr);
    } else {
        die("ID is not set", conn);
    }
}

void Database_delete(struct Connection *conn, int id)
{
    struct Address addr = { .id = id, .set = 0 };
    conn->db->rows[id] = addr;
}

void Database_list(struct Connection *conn)
{
    int i = 0;
    struct Database *db = conn->db;

    for (i = 0; i < MAX_ROWS; i++) {
        struct Address *cur = &db->rows[i];

        if (cur->set) {
            Address_print(cur);
        }
    }
}

// need to write args funcs for this guy
// write something to find in the db

void Database_find_name(struct Connection *conn, char *name)
{
    int i = 0;
    struct Database *db = conn->db;

    for (i = 0; i < MAX_ROWS; i++) {
        struct Address *current = &db->rows[i];

        if (strcmp(current->name, name) == 0 ){
            Address_print(current);
        }
    }
}




int main(int argc, char *argv[])
{
    if (argc < 3){
        die("USAGE: ex17 <dbfile> <action> [action params]", NULL);
    }

    char *filename = argv[1];
    char action = argv[2][0];
    struct Connection *conn = Database_open(filename, action);
    char *findarg;
    char *value;
    int id = 0;

    if (argc > 3 && argc != 5) {
        id = atoi(argv[3]);
    }

    if (id >= MAX_ROWS) {
        die("THERES NOT THAT MANY RECORDS", conn);
    }

    if (argc == 5) {
        findarg = argv[3];
        value = argv[4];
    }

    switch (action) {
        case 'c':
            Database_create(conn);
            Database_write(conn);
            break;

        case 'g':
            if (argc != 4)
                die("Need an id to get", conn);

            Database_get(conn, id);
            break;

        case 'f':
            if (argc != 5){
                die("Need a name to search for", conn);
            }

            if (strcmp(findarg, "name") == 0) {
                Database_find_name(conn, value);
            }
            break;

        case 's':
            if (argc != 7)
                die("Need it, name, email to set", conn);

            Database_set(conn, id, argv[4], argv[5], argv[6]);
            Database_write(conn);
            break;

        case 'd':
            if (argc != 4)
                die("Need id to delete.", conn);

            Database_delete(conn, id);
            Database_write(conn);
            break;

        case 'l':
            Database_list(conn);
            break;
        default:
            die("Invalid action: c=create, g=get, s=set, d=del, l=list", conn);
    }

    Database_close(conn);

    return 0;
}











