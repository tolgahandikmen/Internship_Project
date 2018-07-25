#include "AngelMethodHeader.h"

bool AngelMethodHeader::subOfAngels(list <Graph> edge, double lat, double lgt) {

	double angle, vectorDot, len, X1, Y1, X2, Y2;
	int	inside_flag;
	
 	X1 = edge.back().getX() - lat;
	Y1 = edge.back().getY() - lgt;

	len = (sqrt(pow(X1, 2) + pow(Y1, 2)));
	if (len <= 0.0) return true;		/* point and vertex coincide */
	
	X1 /= len;
	Y1 /= len;
	angle = 0.0;

	for (list<Graph>::iterator itr = edge.begin(); itr != edge.end(); ++itr){
		X2 = itr->getX() - lat;
		Y2 = itr->getY() - lgt;

		len = sqrt(pow(X2, 2) + pow(Y2, 2));
		if (len <= 0.0) return true;		/* point and vertex coincide */
		X2 /= len;
		Y2 /= len;

		/* check if (x2,y2) is to "left" or "right" of (x1,y1) */
		vectorDot = (X1*X2) + (Y1*Y2);

		if (vectorDot < -1.0) {
			/* point is on edge, so always add 180 degrees.  always
			* adding is not necessarily the right answer for
			* concave polygons and subtractive triangles.
			*/
			angle += M_PI;

		}
		else if (vectorDot < 1.0) {
			if (X1*Y2 - X2*Y1 >= 0.0) {
				/* add angle due to dot product of vectors */
				angle += acos(vectorDot);
			}
			else {
				/* subtract angle due to dot product of vectors */
				angle -= acos(vectorDot);
			}
		} /* if vec_dot >= 1.0, angle does not change */

		X1 = X2;
		Y1 = Y2;
	}
	inside_flag = fmod(fabs(angle) + M_PI, 4.0*M_PI) > 2.0*M_PI;
	if (inside_flag) return true;
	else return false;
}