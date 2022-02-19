#include "binding.h"

void source(const char *name) {
    SEXP e;

    PROTECT(e = lang2(install("source"), mkString(name)));
    R_tryEval(e, R_GlobalEnv, NULL);
    UNPROTECT(1);
}

SEXP new_integer_vector(int len, int *a) {
    SEXP arg;
    PROTECT(arg = allocVector(INTSXP, len));
    memcpy(INTEGER(arg), a, len * sizeof(int));
    return arg;
}

/**
 * Wrapper for R function add1, defined in func.R.
 */
void R_add1(SEXP arg) {
    // Set up a call to the R function
    SEXP add1_call;
    PROTECT(add1_call = lang2(install("add1"), arg));

    // Execute the function
    int errorOccurred;
    SEXP ret = R_tryEval(add1_call, R_GlobalEnv, &errorOccurred);

    if (!errorOccurred) {
        printf("R returned: ");

        double *val = REAL(ret);
        for (int i = 0; i < LENGTH(ret); i++) {
            printf("%0.1f, ", val[i]);
        }

        printf("\n");
    } else {
        printf("Error occurred calling R\n");
    }

    UNPROTECT(2);
}

void init_embedded_r() {
    // Init R environment
    int r_argc = 2;
    char *r_argv[] = {"R", "--silent"};
    Rf_initEmbeddedR(r_argc, r_argv);
}

void release_embedded_r() {
    // Release R environment
    Rf_endEmbeddedR(0);
}

int invoke(SEXP arg) {
    // Invoke a function in R
    source("func.R");
    R_add1(arg);
    return (0);
}
