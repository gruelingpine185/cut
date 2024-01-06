#include <stdio.h>
#include "../inc/cut/cut.h"


typedef struct cut_report cut_report;
typedef struct cut_config cut_config;


struct cut_report {
    int tests;
    int passed;
    int failed;
};

struct cut_config {
    cut_setup_fn setup_fn;
    cut_teardown_fn teardown_fn;
    cut_option opts;
}; 


static cut_report cut_internal_report = {0};
static cut_config cut_internal_config = {0};
static int cut_ret = 0;


void cut_setup(cut_setup_fn _setup_fn,
                cut_teardown_fn _teardown_fn,
                cut_option _opts) {
    cut_internal_config.setup_fn = _setup_fn;
    cut_internal_config.teardown_fn = _teardown_fn;
    cut_internal_config.opts = _opts;
}

void cut_run_test(cut_test_fn _test_fn) {
    if(!_test_fn) return;

    if(cut_internal_config.setup_fn) cut_internal_config.setup_fn();

    cut_internal_report.tests++;
    _test_fn();
    if(cut_internal_config.teardown_fn) cut_internal_config.teardown_fn();

    if(!cut_ret) return;
}

void cut_display_report(void) {
    if(cut_internal_report.failed) printf("\n");

    printf("Tests Ran: %d, ", cut_internal_report.tests);
    if(!cut_internal_report.passed) {
        printf("Passed: %d, ", cut_internal_report.passed);
    } else {
        printf("Passed: \x1b[32m%d\x1b[0m, ", cut_internal_report.passed);
    }

    if(!cut_internal_report.failed) {
        printf("Failed: %d\n", cut_internal_report.failed);
    } else {
        printf("Failed: \x1b[31m%d\x1b[0m\n", cut_internal_report.failed);
    }
}
