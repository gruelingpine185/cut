#ifndef CUT_CUT_H
#define CUT_CUT_H


#define CUT_XSTRINGIFY(_data) #_data
#define CUT_STRINGIFY(_data) CUT_XSTRINGIFY(_data)
#define CUT_ERROR_POS __FILE__, __LINE__

#define cutCheck(_test)                                             \
    do {                                                            \
        cut_check(_test);                                           \
        cut_handle_failure(CUT_STRINGIFY(_test), CUT_ERROR_POS);    \
        cut_handle_options();                                       \
    } while(0)


typedef enum {
    CUT_DEFAULT             = 0 << 0,
    CUT_EXIT_ON_ERROR       = 1 << 0,
    CUT_ERROR_WITH_REPORT   = 1 << 1
} cut_option;

typedef void (*cut_setup_fn)(void);
typedef void (*cut_teardown_fn)(void);
typedef void (*cut_test_fn)(void);


#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
void cut_setup(cut_setup_fn _setup_fn,
                cut_teardown_fn _teardown_fn,
                cut_option _opts);
void cut_run_test(cut_test_fn _test_fn);
void cut_display_report(void);
void cut_check(int _res);
void cut_handle_options(void);
void cut_handle_failure(const char* _test, const char* _fname, int _ln);
#ifdef __cplusplus
}
#endif // __cplusplus

#endif // CUT_CUT_H
