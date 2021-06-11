#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

void exercise1_3(GLFWwindow* window)
{
	float prev_time = float(glfwGetTime());
	float angle = 0.0f;

	while (!glfwWindowShouldClose(window))
	{
		float time = float(glfwGetTime());
		if (time - prev_time >= 0.01f) {
			angle += 0.1f;
			prev_time = time;
		}

		glClearColor(float(sin(angle)), float(cos(angle)), float(tan(angle)), 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}



int main()
{

	// Initialize GLFW
	glfwInit();

	// Tell GLFW what version of OpenGL we are using 
	// In this case we are using OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Tell GLFW we are using the CORE profile
	// So that means we only have the modern functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);



	// Create a GLFWwindow object of 800 by 800 pixels, naming it "I made this"
	GLFWwindow* window = glfwCreateWindow(400, 255, "I made this", NULL, NULL);
	// Error check if the window fails to create
	if (window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	// Introduce the window into the current context
	glfwMakeContextCurrent(window);


	//Load GLAD so it configures OpenGL
	gladLoadGL();
	// Specify the viewport of OpenGL in the Window
	// In this case the viewport goes from x = 0, y = 0, to x = 400, y = 255
	glViewport(0, 0, 400, 255);


	// Specify the color of the background
	glClearColor(1.0f, 0.37f, 0.07f, 1.0f);
	// Clean the back buffer and assign the new color to it
	glClear(GL_COLOR_BUFFER_BIT);
	// Swap the back buffer with the front buffer
	glfwSwapBuffers(window);


	// Main while loop
	while (!glfwWindowShouldClose(window))
	{
		// Take care of all GLFW events
		glfwPollEvents();
	}
	// uncomment to do exercise 1.3
	//exercise1_3(window);


	// Delete window before ending the program
	glfwDestroyWindow(window);
	// Terminate GLFW before ending the program
	glfwTerminate();
	return 0;
}