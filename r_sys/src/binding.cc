#include "binding.h"

/**
 * Create new R vector
 */
SEXP c(u_int32_t len, int *val) {
    SEXP arg;

    PROTECT(arg = allocVector(INTSXP, len));
    memcpy(INTEGER(arg), val, len * sizeof(int));
    return arg;
}

/**
 * Load R function to environment
 */
void r_load(const char *name) {
    SEXP e;

    PROTECT(e = lang2(install("source"), mkString(name)));
    R_tryEval(e, R_GlobalEnv, NULL);
    UNPROTECT(1);
}

/**
 * Invoke R function
 */
void r_call(const char *name, SEXP arg) {
    SEXP func_;
    PROTECT(func_ = lang2(install(name), arg));

    // Execute the function
    int errorOccurred;
    SEXP ret = R_tryEval(func_, R_GlobalEnv, &errorOccurred);

    if (!errorOccurred) {
        double *val = REAL(ret);
        for (int i = 0; i < LENGTH(ret); i++) {
            printf("%d, ", (int) val[i]);
        }
        printf("\n");
    } else {
        printf("Error occurred calling R\n");
    }

    UNPROTECT(2);
}

// Init R environment
void init_vm_r() {
    int r_argc = 2;
    char *r_argv[] = {"R", "--silent"};

    Rf_initEmbeddedR(r_argc, r_argv);
}

// Release R environment
void release_vm_r() {
    Rf_endEmbeddedR(0);
}
