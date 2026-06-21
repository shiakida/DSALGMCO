#include <stdio.h>
#include <stdlib.h>

static int find_anchor_idx(Point *pts, int n)
{
    int i;   
    int idx;  
 
    idx = 0;
 
    for (i = 1; i < n; i++) {
        if (pts[i].y < pts[idx].y ||
           (pts[i].y == pts[idx].y && pts[i].x < pts[idx].x))
            idx = i;
    }
 
    return idx;
}
void graham_scan_fast(Point *pts, int n, Stack *hull)
{
    clock_t start_time;  /* clock tick at algorithm start */
    clock_t end_time;    /* clock tick at algorithm end */
    int     anchor_idx;  /* index of anchor in pts[] */
    Point   anchor;      /* the anchor point (min y, then min x) */
    Point   tmp;        
    int     m;           /* compacted array size after removing collinear dups */
    int     i;          
 
    start_time = clock();   /* record start time (as in empirical-time.c) */
 
    anchor_idx      = find_anchor_idx(pts, n);
    tmp             = pts[0];
    pts[0]          = pts[anchor_idx];
    pts[anchor_idx] = tmp;
    anchor          = pts[0];

    fast_sort(pts + 1, n - 1, anchor);
    m = 1;   
 
    for (i = 1; i < n; i++) {
        while (m > 0 && cross_product(anchor, pts[m], pts[i]) == 0.0)
            m--;
 
        m++;
        pts[m] = pts[i];
    }
    /* If fewer than 3 points remain, hull is degenerate */
    CREATE(hull);
 
    if (m < 2) {
        for (i = 0; i <= m; i++)
            PUSH(hull, pts[i]);
 
        end_time = clock();
        printf("[FAST] Elapsed time: %lf ms\n",
               (double)(end_time - start_time) / CLOCKS_PER_SEC * 1000.0);
        return;
    }
    PUSH(hull, pts[0]);
    PUSH(hull, pts[1]);
    PUSH(hull, pts[2]);
 
    for (i = 3; i <= m; i++) {
        while ((*hull).top >= 1 &&
               cross_product(NEXT_TO_TOP(hull), TOP(hull), pts[i]) <= 0.0)
            POP(hull);
 
        PUSH(hull, pts[i]);
    }
 
    end_time = clock();
    printf("[FAST] Elapsed time: %lf ms\n",
           (double)(end_time - start_time) / CLOCKS_PER_SEC * 1000.0);
}
