#ifndef __GETOPT_H__
#define __GETOPT_H__

extern char *optarg; /* Global argument pointer. */
extern int  optind;  /* Global argv index. */

int getopt(int argc, char *argv[], const char *optstring);

#endif
