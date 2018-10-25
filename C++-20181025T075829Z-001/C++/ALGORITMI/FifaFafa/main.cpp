#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>

using namespace std ;

struct point
{
    double x ;
    double y ;
} fafa, flatCenter ;

struct circle
{
    point coordinates ;
    double R ;
} flat ;

double pointDistance ( point A, point B )
{
    return sqrt ( (B.y - A.y) * (B.y - A.y) + (B.x - A.x) * (B.x - A.x) ) ;
}

bool isInside ( point A )
{
    if ( (A.x - flat.coordinates.x) * (A.x - flat.coordinates.x) + (A.y - flat.coordinates.y) * (A.y - flat.coordinates.y) <= flat.R * flat.R )
        return 1 ;
    return 0 ;
}

int main()
{
    cin >> flat.R >> flat.coordinates.x >> flat.coordinates.y >> fafa.x >> fafa.y ;

    flatCenter.x = flat.coordinates.x ;
    flatCenter.y = flat.coordinates.y ;

    if ( flatCenter.x == fafa.x && flatCenter.y == fafa.y )
    {
        flatCenter.x = 0 ;
        flatCenter.y = 0 ;

        double xX = flatCenter.x - 0.01 ;
        double yY = sqrt( flat.R * flat.R - xX * xX ) ;

        double xSol = abs ( xX + fafa.x ) / 2 ;
        double ySol = abs ( yY + fafa.y ) / 2 ;

        xSol += flat.coordinates.x ;
        ySol += flat.coordinates.y ;

        cout << setprecision(8) << fixed << xSol << ' ' << ySol << ' ' << flat.R ;
        return 0;
    }

    if ( !isInside(fafa) )
        cout << setprecision(8) << fixed << flat.coordinates.x << ' ' << flat.coordinates.y << ' ' << flat.R ;
    else
    {
        double dist1 = pointDistance(fafa, flatCenter) ;
        double slope1, xX, yY, a, b, c, delta, xSol, ySol, yySol = 0, xxSol = 0, xXX = 0,yYY = 0 ;

        fafa.x -= flatCenter.x ;
        fafa.y -= flatCenter.y ;
        flatCenter.x = 0 ;
        flatCenter.y = 0 ;

        if ( flatCenter.x == fafa.x )
        {
            xX = fafa.x ;
            yY = sqrt( flat.R * flat.R - xX * xX );

            if ( fafa.y == yY )
                yY = -yY ;
        }
        else if ( flatCenter.y == fafa.y )
        {
            yY = fafa.y ;
            xX = sqrt( flat.R * flat.R - yY * yY );

            if ( fafa.x == xX )
                xX = -xX ;
        }
        else
        {
            slope1 = (flatCenter.y - fafa.y) / (flatCenter.x - fafa.x) ;

            a = slope1 * slope1 + 1  ;
            b = (-1) * 2 * slope1 * ( slope1 * fafa.x - fafa.y) ;
            c = fafa.y * fafa.y  + slope1 * slope1 * fafa.x * fafa.x - 2 * slope1 * fafa.x * fafa.y - flat.R * flat.R ;

            delta = b * b - 4 * a * c ;
            xX = ( (-1) * b + sqrt(delta) ) / ( (double) 2 * a ) ;
            yY = sqrt( abs(flat.R * flat.R - xX * xX) ) ;
        }

        xSol = abs( xX + fafa.x ) / 2 ;
        ySol = abs( yY + fafa.y ) / 2 ;

        xSol += flat.coordinates.x ;
        ySol += flat.coordinates.y ;

        cout << setprecision(8) << fixed << xSol << ' ' << ySol << ' ' ;

        dist1 += flat.R ;
        dist1 /= 2 ;

        cout << setprecision(8) << dist1 ;
    }


    return 0;
}
