/* Aida Colovic
 *
 * Kattis Problem   : Convex Hull
 * Problem ID       : convexhull
 * CPU Time limit   : 1 sec
 * Memory limit     : 1024 MB
 * Difficultiy      : 5.0
 *
 * Source:
 *  https://www.youtube.com/watch?v=B2AJoQSZf4M
 *  https://github.com/JonSteinn/Kattis-Solutions/blob/master/src/Convex%20Hull/C/main.c
 */

#include <iostream>
#include <vector>
#include<deque>
#include<algorithm>

struct Point
{
    int x, y;
};

Point first;

int orientation(Point *p0, Point *p1, Point *p2) {
    int x = (p1->y - p0->y) * (p2->x - p1->x) - (p1->x - p0->x) * (p2->y - p1->y);
    return (x > 0) - (x < 0);
}

int dist_sq(Point *p0, Point *p1) {
    int dx = p0->x - p1->x;
    int dy = p0->y - p1->y;
    return dx*dx + dy*dy;
}

int angle_comparator(const void *a, const void *b) {
    Point *_a = (Point*) a;
    Point *_b = (Point*) b;
    int o = orientation(&first, _a, _b);
    return o ? o : dist_sq(&first, _a) - dist_sq(&first, _b);
}

int read_points(Point *points, int n) {
    int sw = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &points[i].x, &points[i].y);
        // To avoid duplicate sw's
        if (i > 0 && points[i].x == points[sw].x && points[i].y == points[sw].y) {
            i--;
            n--;
            continue;
        }
        if (points[i].y < points[sw].y || (points[i].y == points[sw].y && points[i].x < points[sw].x)) sw = i;
    }
    if (sw != 0) {
        points[sw].x ^= points[0].x ^= points[sw].x ^= points[0].x;
        points[sw].y ^= points[0].y ^= points[sw].y ^= points[0].y;
    }
    first = points[0];
    return n;
}

int trim_points(Point *points, int n) {
    int size = 1;
    for (int i = 1; i < n; i++) {
        while (i < n-1 && !orientation(&points[0],&points[i],&points[i+1])) i++;
        points[size].x = points[i].x;
        points[size].y = points[i].y;
        size++;
    }
    return size;
}

void graham_scan(Point *points, int n) {
    Point hull[n];
    int hull_s = 3;
    for (int i = 0; i < 3; i++) hull[i] = points[i];

    for (int i = 3; i < n; i++) {
        while (orientation(&hull[hull_s-2], &hull[hull_s-1], &points[i]) >= 0) {
            hull_s--;
        }
        hull[hull_s++] = points[i];
    }

    printf("%d\n", hull_s);
    for (int i = 0; i < hull_s; i++) printf("%d %d\n", hull[i].x, hull[i].y);
}

int main() {
    while(1) {
        int n;
        std::cin >> n;
        if (!n) break;

        std::vector<Point> points(n);
        n = read_points(&points[0], n);

        qsort(&points[1], n-1, sizeof(Point), angle_comparator); //sort the points by angle

        n = trim_points(&points[0], n);
        if (n < 3) {
            printf("%d\n", n);
            for (int i = 0; i < n; i++) printf("%d %d\n", points[i].x, points[i].y);
        } else {
            graham_scan(&points[0], n);
        }
    }
    return 0;
}
