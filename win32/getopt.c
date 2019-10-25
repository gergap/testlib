#include <stdio.h>
#include <string.h>

char        *optarg = NULL; /* Global argument pointer. */
int          optind = 0;    /* Global argv index.       */
static char *scan   = NULL; /* Private scan pointer.    */

/** Parse command-line options.
 * The getopt() function parses the command-line arguments.
 * Its arguments argc and argv are the argument count and array as passed to
 * the main() function on program invocation. An element of argv that starts
 * with '-' (and is not exactly "-" or "--") is an option element.
 * The characters of this element (aside from the initial '-') are option
 * characters. If getopt() is called repeatedly, it returns successively each
 * of the option characters from each of the option elements.
 * See getopt(3) manpage for more information.
 */
int getopt(int argc, char *argv[], const char *optstring)
{
    register char  c     = '\0';
    register char *place = NULL;

    optarg = NULL;

    if (scan == NULL || *scan == '\0') {
        if (optind == 0) {
            optind++;
        }

        if (optind >= argc || argv[optind][0] != '-' || argv[optind][1] == '\0') {
            return EOF;
        }

        if (strcmp(argv[optind], "--") == 0) {
            optind++;
            return EOF;
        }

        scan = argv[optind] + 1;
        optind++;
    }

    c = *scan++;
    place = strchr(optstring, c);

    if (place == NULL || c == ':') {
        fprintf(stderr, "%s: unknown option -%c\n", argv[0], c);
        return '?' ;
    }

    place++;

    if (*place == ':') {
        if (*scan != '\0') {
            optarg = scan;
            scan = NULL;
        } else if (optind < argc) {
            optarg = argv[optind];
            optind++;
        } else {
            fprintf(stderr, "%s: -%c argument missing\n", argv[0], c);
            return '?';
        }
    }

    return c;
}

