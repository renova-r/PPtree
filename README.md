# PPtree

Fits classification trees using projection pursuit.

Compatibility updates by Renova.

Registers native routines, declares R imports, and gives an internal C helper a name that avoids the iszero macro.

## Installation

```r
install.packages("PPtree", repos = c(
  Renova = "https://renova-r.r-universe.dev",
  CRAN = "https://cloud.r-project.org"
))
```

Version `2.3.0.9002` is based on [CRAN 2.3.0](https://cran.r-project.org/package=PPtree).

Renova supplies archived penalizedLDA 1.1 from its pinned upstream revision. CRAN supplies flsa. [Pinned penalizedLDA source](https://github.com/cran/penalizedLDA/tree/7f3d3654660329d799272252d3c1120f77c27cc6)

## Credit

Eun-Kyung Lee, Yoondong Lee.

Licensed under `LGPL-2.1`.
