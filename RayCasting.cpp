#include "RayCasting.h"

bool RayCasting::isInside(std::list <Graph> edge, double lat, double lgt){

#ifdef	WINDING
	int	crossing;
#endif

	list <Graph> itrEdge;
	std::copy(edge.begin(), edge.end(), std::back_inserter(itrEdge));

	double X1, Y1, X2, Y2;
	int	yflag0, yflag1, inside_flag, xflag0;

#ifdef	CONVEX
	int	line_flag;
#endif

	X2 = edge.back().getX();
	Y2 = edge.back().getY();

	/* get test bit for above/below X axis */
	yflag0 = (Y2 >= lgt);

	X1 = itrEdge.front().getX();
	Y1 = itrEdge.front().getY();
	itrEdge.pop_front();

#ifdef	WINDING
	crossing = 0;
#else
	inside_flag = 0;
#endif
#ifdef	CONVEX
	line_flag = 0;
#endif

	for (list<Graph>::iterator itr = edge.begin(); itr != edge.end(); ++itr){
		yflag1 = (Y1 >= lgt);
		/* check if endpoints straddle (are on opposite sides) of X axis
		* (i.e. the Y's differ); if so, +X ray could intersect this edge.
		*/

		if (yflag0 != yflag1) {
			xflag0 = (X2 >= lat);
			/* check if endpoints are on same side of the Y axis (i.e. X's
			* are the same); if so, it's easy to test if edge hits or misses.
			*/
			if (xflag0 == (X1 >= lat)) {

				/* if edge's X values both right of the point, must hit */
#ifdef	WINDING
				if (xflag0) crossing += (yflag0 ? -1 : 1);
#else
				if (xflag0) inside_flag = !inside_flag;
#endif
			}
			else {
				/* compute intersection of pgon segment with +X ray, note
				* if >= point's X; if so, the ray hits it.
				*/
				if ((X1 - (Y1 - lgt)*
					(X2 - X1) / (Y2 - Y1)) >= lat) {
#ifdef	WINDING
					crossing += (yflag0 ? -1 : 1);
#else
					inside_flag = !inside_flag;
#endif
				}
			}
#ifdef	CONVEX
			/* if this is second edge hit, then done testing */
			if (line_flag) goto Exit;

			/* note that one edge has been hit by the ray's line */
			line_flag = TRUE;
#endif
		}
		/* move to next pair of vertices, retaining info as possible */
		yflag0 = yflag1;
		X2 = X1;
		Y2 = Y1;

		if (!itrEdge.empty()){
			X1 = itrEdge.front().getX();
			Y1 = itrEdge.front().getY();
			itrEdge.pop_front();
		}
	}
#ifdef	CONVEX
Exit : ;
#endif
#ifdef	WINDING
	/* test if crossings is not zero */
	inside_flag = (crossing != 0);
#endif

	if (inside_flag) return true;
	else return false;
}