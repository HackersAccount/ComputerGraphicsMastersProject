#!/bin/bash

# Directory where the main.cpp files will be created
main_dir="src"

# Template for the main function
main_template="
#include <iostream>

// Main function following SOLID principles
int main() {
    try {
        // TODO: Add code specific to this concept
        
        // Example: Print a message indicating the concept
        std::cout << \"This is a generic main function for the concept.\" << std::endl;
        
        // Example: Placeholder for concept-specific code
        // Replace this with actual implementation
        
        return 0;
    } catch (const std::exception& e) {
        std::cerr << \"An exception occurred: \" << e.what() << std::endl;
        return 1;
    }
}
"

# Loop through each concept directory and create main.cpp file
for concept_dir in "$main_dir"/*; do
    # Check if it's a directory
    if [ -d "$concept_dir" ]; then
        # Create main.cpp file in the concept directory
        echo "$main_template" > "$concept_dir/main.cpp"
        echo "Created main.cpp in $concept_dir"
    fi
done
