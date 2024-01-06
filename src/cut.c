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


void cut_setup(cut_setup_fn _setup_fn,
                cut_teardown_fn _teardown_fn,
                cut_option _opts) {
    cut_internal_config.setup_fn = _setup_fn;
    cut_internal_config.teardown_fn = _teardown_fn;
    cut_internal_config.opts = _opts;
}
