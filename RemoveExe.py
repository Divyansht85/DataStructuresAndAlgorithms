import os

# Get the current directory
current_directory = os.getcwd()

# Loop through all files in the current directory
for filename in os.listdir(current_directory):
    # Check if the file is an .exe file
    if filename.endswith(".exe"):
        # Get the full file path
        file_path = os.path.join(current_directory, filename)
        try:
            # Remove the file
            os.remove(file_path)
            print(f"Removed: {file_path}")
        except Exception as e:
            print(f"Error removing {file_path}: {e}")
