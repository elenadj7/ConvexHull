# ConvexHull
An algorithm for finding the convex hull using the Graham scan with OpenMP optimization.
The convex hull problem involves finding the smallest convex polygon that contains all given points in a 2D plane. The Graham scan algorithm is widely used for this problem and works by sorting the input points by their polar angle with respect to a reference point, and then processing the sorted points in a specific order to determine the convex hull.

# How does the algorithm work? 
The first step is to sort the points in ascending order by their x-coordinate (if the x-coordinates are equal, then sort them in ascending order by their y-coordinate) to determine the leftmost point, A, and the rightmost point, B. Of course, A and B must be part of the convex hull since they are the furthest apart along the x-axis, and therefore cannot be enclosed by the sides of the polygon that connect other pairs of points. Let us draw a line through A and B. Now, we can divide the points into two sets based on which side of the line they lie on: S1, which contains the points "above" the line, and S2, which contains the points "below" the line. We will construct the convex hull from two parts: the upper hull, for which we will select points from S1, and the lower hull, with points from S2.
Let's first construct the upper part by starting with adding point A to the hull. We iterate through the elements S1 sorted by x-coordinate. If there are currently less than two points in the shell, we add the current point T. If there are at least two points in the shell, we check the angle between the line segment connecting the second-to-last (R) and the last (S) added points of the shell and point T. As long as the orientation of the angle RST is not counterclockwise, we remove the last point from the shell, and finally add the current one. When we are above the line AB, "turning left" (angle in the counterclockwise direction) means that the polygon will contain a protruding angle, which is contrary to convexity, so we had to remove some point. The shell with only the second-to-last and the current point as vertices will also include the last point because the orientation ensures that it is below the other two, so we could remove it.
Similarly, we construct the lower part but check if the orientation of the appropriate angle is clockwise. The final convex shell is the union of the upper and lower parts.

# Complexity analysis
In the construction of the convex hull after sorting, each point can appear in operations only twice. For example, consider the set S1. We go through the points from left to right, encountering each point for the first time when we add it to the hull, and then we continue with the algorithm. We can only return to the same point if we determine that it closes an angle in the opposite direction of clockwise, in which case the operation involved is its removal, so it cannot appear again. The same applies to set S2, so the for loop has a complexity of O(n). On the other hand, the sort function has a complexity of O(n²) and dominates the overall execution time. Therefore, the complexity of the entire algorithm is O(n²).

The OpenMP optimization allows for parallel processing, which can significantly reduce the time complexity of the algorithm. The code is well-documented with comments that provide detailed explanations of the optimization techniques utilized by OpenMP in the algorithm.
