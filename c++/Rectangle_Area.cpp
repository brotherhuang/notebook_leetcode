/* Find the total area covered by two rectilinear rectangles in a 2D plane.

Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

Rectangle Area
Assume that the total area is never beyond the maximum possible value of int. */
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area = (C - A) * (D - B) + (G - E) *(H - F);
        if(C < E || G < A || D < F || H < B)
        {
            return area;
        }

        return area - (min(C,G) - max(A,E)) * (min(D,H) - max(B,F));
    }
};
