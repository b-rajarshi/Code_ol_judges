class Solution {
public:
    string convert(string s, int numRows) {
            int s_length = s.length();
            
            // Base case.
            if (numRows == 1 || s_length == 0)
                return s;

            
            int zig = 1 + (numRows - 2);
            int zig_char = numRows + (numRows - 2);
            
           // cout <<zig << " "<< zig_char;
            int numColumn = 0;

    
            // We can complete one zig.
            if (s_length >= zig_char) {
                int num_of_zigs = s_length / zig_char;
                numColumn = zig * num_of_zigs;
                //cout << "---" << numColumn << "++";
            }

            int left_char = s_length % zig_char;

            if (left_char == 0) {
                // Do nothing.
            } else if (left_char <= numRows) {
                //cout << "---" << numColumn << "++";
                numColumn = numColumn + 1;
            } else {
                numColumn = numColumn + 1 + (left_char - numRows);
            }

          //  cout << numRows << numColumn;
            
            char array[numRows][numColumn];
            
            for (int row = 0; row < numRows; row++)
                for (int col = 0; col < numColumn; col++) 
                    array[row][col] = ' ';
                
            int index = 0;
            for (int col = 0; col < numColumn; col = col + zig) {
                // Complete all rows of the first column of zig.
                for (int row = 0; row < numRows; row++) {
                    if (index < s_length) {
                        array[row][col] = s[index];
                        index++;
                    }
                    else
                       goto done;
                } 
                // complete the other columns.
                for (int i = 1; i <= (zig - 1) ; i++) {
                    if (index < s_length) {
                        array[numRows - i - 1][col+i] = s[index];
                        index++;
                    }
                    else 
                        goto done;
                }
                
           }
done:
            string result;
            for (int row = 0; row < numRows; row++) {
                for (int col = 0; col < numColumn  ; col++) {
                    if (array[row][col] != ' ') {
                        result = result + array[row][col];
                    }
                }
            }

            return result;

    }
};