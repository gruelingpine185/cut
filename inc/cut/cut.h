#ifndef CUT_CUT_H
#define CUT_CUT_H


typedef enum {
    CUT_DEFAULT             = 0 << 0,
    CUT_EXIT_ON_ERROR       = 1 << 0,
    CUT_ERROR_WITH_REPORT   = 1 << 1
} cut_option;

typedef void (*cut_setup_fn)(void);
typedef void (*cut_teardown_fn)(void);
typedef void (*cut_test_fn)(void);

#endif // CUT_CUT_H
