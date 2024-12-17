# **Path Planning Agent**

## **1. Introduction**
In this project, the focus is on the decision-making mechanism of an object with detection, decision-making, and movement capabilities, aimed at navigating towards a target point on a two-dimensional plane, based on its size and position.

## **2. Method**
The two-dimensional plane used in this project has dimensions of 100x200. The moving object's coordinates are generated with random values between 25 and 75 for the x-axis and fixed at 190 for the y-axis. Similarly, the target's coordinates have random x-axis components between 35 and 65 and a fixed y-axis component of 5.

The moving object includes three main functions:
- **Detection Function**: This function calculates the distance between the moving object and the target by computing the hypotenuse between their x and y components.
- **Decision Making Function**: Based on the distance calculated from the detection function, this function decides whether to continue moving and determines the direction of movement (e.g., if the target is to the left of the moving object, it will adjust its direction accordingly).
- **Movement Function**: This function moves the object towards the target according to the decision-making instructions. Each movement step involves changing the coordinates by 2 units in both x and y directions.

The object initially has a viewing angle between -30 and +30 degrees. Afterward, subsequent movements are based on a vertical vector extending from the object's body towards the target.

For alpha values of 0.80 and 0.95, the following formula is applied:
```
v1(t) = (1 - alpha) * v2(t) + alpha * v1(t)
```
where `v1` is the unit vector between the target and the object, and `v2` is the unit vector of the moving direction.

For both alpha values, the simulation was run 100 times, and the results were stored in an output file for further analysis.

The project was implemented without any graphical user interface (GUI), but the movement can be visualized through the models below:

### **Models**
- **Model 2.1**: Initial state of the moving object.
- **Model 2.2**: The moving object progresses towards the target.
- **Model 2.3**: The moving object reaches the target and the program terminates.

The detection function determines when the target is reached by checking the distance between the moving object and the target. If this distance is less than 1, the target is considered reached, and the program halts. The coordinates during the movement are saved in the "output.txt" file.

## **3. Results**
The project includes two files with results for the alpha values of 0.95 and 0.80, each executed 100 times. The coordinates of the moving and target objects are recorded in these files:
- **YAP_ODEV1_ALPHA_080**
- **YAP_ODEV1_ALPHA_095**

For the alpha = 0.95 case, the target is reached in 1961 steps in the first trial, while for alpha = 0.80, it takes only 501 steps. The value of alpha significantly affects the number of steps needed to reach the target, with alpha = 0.95 requiring fewer steps due to the smaller multiplier (0.05 vs. 0.20).

These numerical differences reflect the impact of the decision-making mechanism and how more precise calculations in the vector direction reduce the number of movements required.

## **4. Conclusion**
This project focuses on the movement and decision-making process of an object with detection capabilities towards a target. The varying alpha values alter the object's decision-making mechanism, impacting the total number of moves to reach the target. A smaller alpha (0.80) leads to more movement steps, indicating less precision in decision-making. In contrast, a larger alpha (0.95) reduces the number of moves, showing more efficient decision-making and greater accuracy in reaching the target.

## **5. Summary**
This project investigates the impact of changes in detection, decision-making, and movement functions on the path taken by a moving object to reach a given target. The results suggest that a more consistent decision-making process leads to fewer movements, indicating that a higher alpha value results in better precision and fewer decisions required to reach the target.
