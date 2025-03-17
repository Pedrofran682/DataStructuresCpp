#!/bin/bash

dir="src"
shopt -s globstar  # Enable recursive globbing

for subdir in "$dir"/**/; do
    if [[ -d "$subdir" ]]; then  # Ensure it's a directory
        cmakeFilePath="$subdir/CMakeLists.txt"
        if [[ -f "$cmakeFilePath" ]]; then 
            echo "CMakeLists.txt exists in $subdir"
            firstLine=`expr "$(grep -n "### Adding executables" CMakeLists.txt | head -n 1 | cut -d: -f1)" + 1`
            lastLine=`expr "$(grep -n "### Executables added" CMakeLists.txt | head -n 1 | cut -d: -f1)" - 1`
            sed -i "${firstLine},${lastLine}d" "$cmakeFilePath"
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
                    firstLine=`expr "$(grep -n "### Adding executables" "$cmakeFilePath" | head -n 1 | cut -d: -f1)" + 1`
                    lastLine=`expr "$(grep -n "### Executables added" "$cmakeFilePath" | head -n 1 | cut -d: -f1)" - 1`

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
        fi
            else
                echo "Could not find correct markers in $cmakeFilePath"
            fi
        done
    fi
done
