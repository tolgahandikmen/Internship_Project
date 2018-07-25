#include "BadouelTriangle.h"

bool BadouelTriangle::BadouelTriangleTest(list <Graph> edge, double lat, double lgt){
	double pg1X, pg1Y, pg2X, pg2Y, pgendX, pgendY;
	double tx, ty, u0, u1, u2, v0, v1, vx0, vy0, alpha, beta, denom;
	int	inside_flag;

	tx = lat;
	ty = lgt;
	vx0 = edge.front().getX();
	vy0 = edge.front().getY();
	u0 = tx - vx0;
	v0 = ty - vy0;

	inside_flag = 0;
	pgendX = edge.back().getX();
	pgendY = edge.back().getY();

	list<Graph>::iterator itr = edge.begin();
	itr++;
	for (itr; itr != edge.end(); ++itr) {
		pg1X = itr->getX();
		pg1Y = itr->getY();
		pg2X = itr->getAx();
		pg2Y = itr->getAy();

		u1 = pg1X - vx0;

		if (u1 == 0.0) {

			/* 0 and 1 vertices have same X value */

			/* zero area test - can be removed for convex testing */
			u2 = pg2X - vx0;
			if ((u2 == 0.0) ||

				/* compute beta and check bounds */
				/* we use "<= 0.0" so that points on the shared interior
				* edge will (generally) be inside only one polygon.
				*/
				((beta = u0 / u2) <= 0.0) ||
				(beta > 1.0) ||

				/* zero area test - remove for convex testing */
				((v1 = pg1Y - vy0) == 0.0) ||

				/* compute alpha and check bounds */
				((alpha = (v0 - beta *
				(pg2Y - vy0)) / v1) < 0.0)) {

				/* whew! missed! */
				goto NextTri;
			}
		}
		else {
			/* 0 and 1 vertices have different X value */

			/* compute denom and check for zero area triangle - check
			* is not needed for convex polygon testing
			*/
			u2 = pg2X - vx0;
			v1 = pg1Y - vy0;
			denom = (pg2Y - vy0) * u1 - u2 * v1;
			if ((denom == 0.0) ||

				/* compute beta and check bounds */
				/* we use "<= 0.0" so that points on the shared interior
				* edge will (generally) be inside only one polygon.
				*/
				((beta = (v0 * u1 - u0 * v1) / denom) <= 0.0) ||
				(beta > 1.0) ||

				/* compute alpha & check bounds */
				((alpha = (u0 - beta * u2) / u1) < 0.0)) {

				/* whew! missed! */
				goto NextTri;
			}
		}

		/* check gamma */
		if (alpha + beta <= 1.0) {
			/* survived */
			inside_flag = !inside_flag;
		}

	NextTri:;
	}
	return(inside_flag);

}