/*--find minimum distance and closes util  point--Complexity:    O(n logn)--*/
#include <iostream> 
#include <float.h> 
#include <stdlib.h> 
#include <math.h> 
using namespace std; 
struct Point{ 
    int x, y; 
}; 
/*compare two point in X*/
int CompareX(const void* a, const void* b){ 
    Point *point1 = (Point *)a,  *point2 = (Point *)b; 
    return (point1->x - point2->x); 
} 
/*compare two point in X*/
int CompareY(const void* a, const void* b){ 
    Point *point1 = (Point *)a,   *point2 = (Point *)b; 
    return (point1->y - point2->y); 
} 
/*calculate distance between two point in X-Y*/
float Dist(Point point1, Point point2){ 
    return sqrt( (point1.x - point2.x)*(point1.x - point2.x) + 
                 (point1.y - point2.y)*(point1.y - point2.y) 
               ); 
}
/*calculate Minimum distance in B*/
float MinDist_B_Points(Point P[], int n){ 
    float min = FLT_MAX; 
    for (int i = 0; i < n; ++i) 
        for (int j = i+1; j < n; ++j) 
            if (Dist(P[i], P[j]) < min) 
                min = Dist(P[i], P[j]); 
    return min; 
} 
/*find minimum*/
float min(float x, float y){ return (x < y)? x : y;}
/*calculate distance between B with any point */
float Dist_B_anyPoint(Point strip[], int size, float d){ 
    float min = d; 
    for (int i = 0; i < size; ++i) 
        for (int j = i+1; j < size && (strip[j].y - strip[i].y) < min; ++j) 
            if (Dist(strip[i],strip[j]) < min) 
                min = Dist(strip[i], strip[j]); 
  
    return min; 
} 
/*find closes util point*/
float ClosestUtil(Point Px[], Point Py[], int n){ 
    if (n <= 3) 
        return MinDist_B_Points(Px, n); 
    int mid = n/2; 
    Point midPoint = Px[mid]; 
    Point Pyl[mid];
    Point Pyr[n-mid];
    int li = 0, ri = 0;
    for (int i = 0; i < n; i++){ 
      if (Py[i].x <= midPoint.x && li<mid) 
         Pyl[li++] = Py[i]; 
      else
         Pyr[ri++] = Py[i]; 
    } 
    float dl = ClosestUtil(Px, Pyl, mid); 
    float dr = ClosestUtil(Px + mid, Pyr, n-mid); 
    float d = min(dl, dr); 
    Point strip[n]; 
    int j = 0; 
    for (int i = 0; i < n; i++) 
        if (abs(Py[i].x - midPoint.x) < d) 
            strip[j] = Py[i], j++; 
    return Dist_B_anyPoint(strip, j, d); 
}
/*calculate minimum distance closes util point*/
float closest(Point P[], int n){ 
    Point Px[n]; 
    Point Py[n]; 
    for (int i = 0; i < n; i++){ 
        Px[i] = P[i]; 
        Py[i] = P[i]; 
    } 
    qsort(Px, n, sizeof(Point), CompareX); 
    qsort(Py, n, sizeof(Point), CompareY);  
    return ClosestUtil(Px, Py, n); 
} 
/*main function and test*/
int main(){ 
    Point P[] = {{5, 3}, {15, 20}, {30, 60}, {5, 8}, {15, 10}, {3, 4}}; 
    int n = sizeof(P) / sizeof(P[0]); 
    cout << "The Min distance is " << closest(P, n); 
    return 0; 
}
