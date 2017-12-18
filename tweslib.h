#ifndef TWES_LIB_H
#define TWES_LIB_H

#define OUT(fd, opts) ((opts).daemonize ? (fd):stdout)

#define LOG(request, status, opts, fd) { \
    if ((opts).verbose) \
        fprintf(OUT(fd, opts),"%s",(request)->headers); \
    else fprintf(OUT(fd, opts),"%s %s %s %s\n",(request)->method,(request)->path,(request)->protocol,status); \
}

void error(char *msg);
char *get_mime(char *filename);
void *tmalloc(size_t size);

#endif //TWES_LIB_H
