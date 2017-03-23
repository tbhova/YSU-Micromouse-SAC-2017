//Overall drive forward method
void drive() {
	while !atDestination {
		int velocity = distanceController(); //overall robot velocity
		
		int omega = wallController();	//angular velocity
		
		(Vleft, Vright) = differentialDrive(velocity, omega); //change from unicycle model to differential drive
		
		motorController.setSpeeds(Vleft, Vright);
	}
}



// Wall follower - return angular velocity 
enum wallState {
	bothWalls,
	leftWall,
	rightWall,
	noWalls
}

checkpointWall() {
	// useful to know where to turn/stop - eliminates encoder drift error
	wallAt = getDistanceTraveled(); // (leftDistance + rightDistance)/2
}

int wallController() {
	if (isRightWall() && isLeftWall()) {
		error = rightDistance - leftDistance;
		state = wallState.bothWalls;
	} else if (isRightWall()) {
		error = rightDistance - optimalWallDistance;
		if (state != wallState.rightWall) {
			checkpointWall();
		}
		state = wallState.rightWall;
	} else if (isLeftWall()) {
		error = leftDistance - optimalWallDistance;
		
		if (state != wallState.leftWall) {
			checkpointWall();
		}
		state = wallState.leftWall;
	} else {
		if (state != wallState.noWalls) {
			checkpointWall();
		}
		state = wallState.noWalls;
		// drive with encoders only - either omega = 0, or....
		// try and keep track of the global thetha and make it the nearest n*90
		
		
		// encoders only algorithm
		
		// init code - run once on state change
		startTime = millis(); //static variable
		startTheta = HardwareManager.getTheta(); //static variable
		switch (dir) {
			case North:
				desiredAngle = 0;
			case South:
				desiredAngle = 180;
			case West:
				desiredAngle = -90;
			case East:
				desiredAngle = 90;
		}
		
		lastTime = millis();
		
		
		//continuous run code
		lastOmega = 0;
		desiredAngle -= lastOmega * (millis() - lastTime);
		error = desiredAngle - startTheta;
		omega = PID(error*degreesToWallDistCoefficient);
		lastOmega = omega;
		return omega;
	}
	
	return PID(error);
}


// PID - ramp up and down for speed as we leave and square and approach the next
int distanceController() {
	currentDistance = getDistanceTraveled(); // (leftDistance + rightDistance)/2
	error = desiredDistance - currentDistance; // desiredDistance will usually be 180mm (1 cell)
	
	velocity = PID(error)
	
	//limit robot velocity to 75% of the motor's max speed to allow room for turning
	if (velocity > 75% motorCapacity) {
		velocity = 75% motorCapacity;
	}
	
	return velocity;
}


//convert unicycle model to differential drive (v, omega) -> vRight, vLeft
// vLeft  = (2*velcity - omega*wheelbase)/(2*radius)
// vRight = (2*velcity + omega*wheelbase)/(2*radius)
(vLeft, vRight) differentialDrive(velcity, omega) {
	linear = velocity/radius;
	rotational = (omega * wheelbase) / (2 * radius);
	
	vLeft  = linear - rotational;
	vRight = linear + rotational;
	return (vLeft, vRight);
}



// PID loop to make sure the speed we are setting is correct (i.e. we can actually drive in a straight line)
void motorController::setSpeeds(vLeft, vRight) {
	setOneMotorSpeed(leftMotor, leftEncoder, vLeft);
	setOneMotorSpeed(rightMotor, rightEncoder, vRight);
}

void setOneMotorSpeed(motor, encoder, velocity) {
	lastVelocity = motor.getLastVelocity();
	currentVelocity = encoder.getInstantaneousSpeed();
	
	error = currentVelocity - lastVelocity;
	newVelocity = PID(error);
	
	motor.setSpeed(newVelocity);
}