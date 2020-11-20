## Notes

### 2D Simulation (Original)
- Environment Shape: Square with circular arena
- Environment Diameter: 956px
- Robot Body Shape: Circle
- Robot Body Diameter: 5px
- Total Front Sensors: 7
- Front Sensor Positions: Toward the front, uniformly covering 90º
- Total Back Sensors: 5
- Back Sensor Positions: Evenly spaced around the remainder of the body

### 3D Simulation (Reimplementation)
- Environment Shape: Square with circular arena
- Environment Diameter: 25m
- Robot Body Shape: Cylinder
- Robot Body Diameter: (5px / 956px) * 25m = 0.1307531381...m = ~0.13m
- Robot Body Height: 0.05m
- Robot Wheel Diameter: 0.06m
- Robot Wheel Depth: 0.01m
- Robot Left Wheel Position: (-0.07, 0.0, 0.03)
- Robot Right Wheel Position: (0.07, 0.0, 0.03)
- Robot Left/Right Wheel Target Velocity: -50 deg/s // negative so that wheels rotate in the correct direction to move forwards
- Total Front Sensors: 7
- Front Sensor Positions: 
    - Front Left 3: (-0.04619, 0.04587, 0.03)
    - Front Left 2: (-0.0325, 0.05629, 0.03)
    - Front Left 1: (-0.01682, 0.06279, 0.03)
    - Front Centre: (0.0, 0.065, 0.03)
    - Front Right 1: (0.01682, 0.06279, 0.03)
    - Front Right 2: (0.0325, 0.05629, 0.03)
    - Front Right 3: (0.04619, 0.04587, 0.03)
- Total Back Sensors: 5
    - Back Left 2: (-0.075, 0.0, 0.03) // X = -0.075 to place it on the left wheel
    - Back Left 1: (-0.04596, -0.04596, 0.03)
    - Back Centre: (0.0, -0.065, 0.03)
    - Back Right 1: (0.04596, -0.04596, 0.03)
    - Back Right 2: (0.075, 0.0, 0.03) // X = 0.075 to place it on the right wheel
- Back Sensor Positions: Evenly spaced around the remainder of the body