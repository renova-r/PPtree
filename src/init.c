#include <R.h>
#include <Rinternals.h>
#include <stdlib.h> /* for NULL */
#include <R_ext/Rdynload.h>

/*  .C entry points called from R/PPindex.R  */
void discriminant1(int *fn, int *fp, int *groups, double *fvals,
                   int *groupraw, int *gname, int *ngroup, double *val);
void discriminant2(int *fn, int *fp, int *groups, double *fvals,
                   int *groupraw, int *gname, int *ngroup, double *val);
void discriminant3(int *fn, int *fp, int *groups, double *fvals,
                   int *groupraw, int *gname, int *ngroup, double *val,
                   int *r);
void pda(int *fn, int *fp, int *groups, double *fvals, int *groupraw,
         int *gname, int *ngroup, double *val, double *lambda);
void optimize1(int *fn, int *fp, int *groups, double *fvals, int *groupraw,
               int *gname, int *ngroup, int *method, double *cooling,
               double *temp_start, int *projdim, double *val, double *proj,
               int *r, double *lambda);
void optimize2(int *fn, int *fp, int *groups, double *fvals, int *groupraw,
               int *gname, int *ngroup, int *method, double *cooling,
               double *temp_start, int *projdim, double *val, double *proj,
               double *energy, int *r, double *lambda);
void optimize3(int *fn, int *fp, int *groups, double *fvals, int *groupraw,
               int *gname, int *ngroup, int *method, double *cooling,
               double *temp_start, int *projdim, double *val, double *proj,
               int *r, double *lambda);

/*  The argument counts are those of the .C() calls in R/PPindex.R (they are
    checked against registered routines); PP.optimize.Huber() has always
    supplied 14 arguments to optimize3, without lambda.  */
static const R_CMethodDef CEntries[] = {
    {"discriminant1", (DL_FUNC) &discriminant1,  8},
    {"discriminant2", (DL_FUNC) &discriminant2,  8},
    {"discriminant3", (DL_FUNC) &discriminant3,  9},
    {"pda",           (DL_FUNC) &pda,            9},
    {"optimize1",     (DL_FUNC) &optimize1,     15},
    {"optimize2",     (DL_FUNC) &optimize2,     16},
    {"optimize3",     (DL_FUNC) &optimize3,     14},
    {NULL, NULL, 0}
};

void R_init_PPtree(DllInfo *dll)
{
    R_registerRoutines(dll, CEntries, NULL, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
