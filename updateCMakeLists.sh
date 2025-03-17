#!/bin/bash

dir="src"
shopt -s globstar  # Enable recursive globbing

for subdir in "$dir"/**/; do
    if [[ -d "$subdir" ]]; then  # Ensure it's a directory
        cmakeFilePath="$subdir/CMakeLists.txt"
        
        if [[ -f "$cmakeFilePath" ]]; then
            echo "CMakeLists.txt exists in $subdir"
            
            firstLine=$(grep -n "### Adding executables" "$cmakeFilePath" | head -n 1 | cut -d: -f1)
            lastLine=$(grep -n "### Executables added" "$cmakeFilePath" | head -n 1 | cut -d: -f1)
            
            if [[ -n "$firstLine" && -n "$lastLine" && "$firstLine" -lt "$lastLine" ]]; then
                firstLine=$((firstLine + 1))
                lastLine=$((lastLine - 1))
                sed -i "${firstLine},${lastLine}d" "$cmakeFilePath"
            else
                echo "Could not find correct markers in $cmakeFilePath"
            fi
        else
            echo "There is no CMakeLists.txt in $subdir. Creating from template."
            cp ".template/CMakeLists.txt" "$cmakeFilePath"
        fi
        
        # Loop over files inside the current directory
        for file in "$subdir"*; do
            if [[ -f "$file" ]]; then
                extension="${file##*.}"
                
                if [[ "$extension" =~ ^(h|c|cpp|cxx)$ ]]; then
                    echo "Valid file: $file"
                    
                    firstLine=$(grep -n "### Adding executables" "$cmakeFilePath" | head -n 1 | cut -d: -f1)
                    lastLine=$(grep -n "### Executables added" "$cmakeFilePath" | head -n 1 | cut -d: -f1)
                    
                    if [[ -n "$firstLine" && -n "$lastLine" && "$firstLine" -lt "$lastLine" ]]; then
                        firstLine=$((firstLine + 1))
                        lastLine=$((lastLine - 1))
                        fileName="${file%%.*}"
                        fileName="${fileName##*/}"
                        fullFileName="${file##*/}"
                        
                        echo "Updating file: $fileName"
                        
                        ex "$cmakeFilePath" <<EOF
$firstLine insert
add_executable($fileName $fullFileName)
.
xit
EOF
                    else
                        echo "Could not find correct markers in $cmakeFilePath for $file"
                    fi
                fi
            fi
        done
    fi
done
