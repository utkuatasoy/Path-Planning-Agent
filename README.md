# **Path-Planning-Agent**

## **1. Introduction**
This project focuses on an object's path-planning mechanism with detection, decision-making, and movement functions to navigate towards a target on a 2D plane.

## **2. Method**
A 100x200 2D plane is used. The moving object’s coordinates are randomly set between 25-75 for the x-axis and fixed at 190 for the y-axis. The target's x-axis components are randomly set between 35-65, and its y-axis component is fixed at 5.

Key functions:
- **Detection**: Calculates the distance between the object and the target.
- **Decision-Making**: Decides the movement direction based on the distance.
- **Movement**: Moves the object towards the target, changing coordinates by 2 units.

Alpha values of 0.80 and 0.95 are used to modify the decision-making process. Each scenario was run 100 times, and results were saved in "output.txt".

## **3. Results**
The results for alpha = 0.80 and alpha = 0.95 (executed 100 times each) are recorded in:
- **YAP_ODEV1_ALPHA_080**
- **YAP_ODEV1_ALPHA_095**

For alpha = 0.95, the target is reached in 1961 steps; for alpha = 0.80, it takes 501 steps. A higher alpha value reduces the number of steps, indicating more efficient decision-making.

## **4. Conclusion**
The project shows that adjusting alpha affects the precision of the decision-making process, with a higher alpha leading to fewer movements and a more accurate path.

## **5. Summary**
This project explores how varying the alpha value in the decision-making function influences the number of steps needed to reach a target. Higher alpha values result in fewer movements and more efficient decision-making.
