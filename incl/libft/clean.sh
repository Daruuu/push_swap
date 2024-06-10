find . -type f \( -name "a.out" -o -name "*.o" -o -name "*.a" -o -name "*.h.gch" \) -exec rm -f {} \;
