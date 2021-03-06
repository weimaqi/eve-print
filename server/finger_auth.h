#ifndef __FINGER_AUTH_H
#define __FINGER_AUTH_H

#include <stdio.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> //for sleep
#include <libfprint/fprint.h>
#include <errno.h>

#define PRINT_NAME_SIZE 50
#define PRINT_FILE_BUFFER_SIZE 4096
#define PRINT_DEFAULT_PATH "~/prints/"
#define PRINT_EXT "fp"

#define false 0
#define true 1
typedef int bool;

//TODO use fp_handle_events_timeout or fp_handle_events to detect device replug

struct user_prints {
    struct fp_print_data ** prints;
    char ** names;
    size_t length;
};

struct fp_dscv_dev *discover_device(struct fp_dscv_dev **discovered_devs);
struct fp_dev* fp_connect();
void fp_disconnect(struct fp_dev *dev);
struct fp_print_data * load_print_from_file(const char * path);
void loadPrints(char *path, struct user_prints *users);
bool enroll(struct fp_dev *dev, struct fp_print_data **enrolled_print);
bool verify(struct fp_dev* dev, struct fp_print_data *data);
int identify(struct fp_dev * dev, struct user_prints * users);
void freePrints(struct user_prints *data);

bool create_dir(const char * path);
bool file_exists(const char * filename);

#endif
