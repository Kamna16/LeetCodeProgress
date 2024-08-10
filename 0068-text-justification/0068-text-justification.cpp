class Solution {
public:
    int MAX_WIDTH;

    string findLine(int i, int j, int eachSlotsSpace, int extraSlotsSpace, vector<string>& words, bool lastLine = false)
    {
        string line;
        for (int k = i; k < j; k++)
        {
            line += words[k];
            if (k == j - 1)
            {
                break;
            }

            if (lastLine)
            {
                line += " ";
            }
            else
            {
                for (int z = 1; z <= eachSlotsSpace; z++)
                {
                    line += " ";
                }
                if (extraSlotsSpace > 0)
                {
                    line += " ";
                    extraSlotsSpace--;
                }
            }
        }

        while (line.length() < MAX_WIDTH)
        {
            line += " ";
        }

        return line;
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth)
    {
        vector<string> ans;
        int n = words.size();
        MAX_WIDTH = maxWidth;
        int i = 0;

        while (i < n)
        {
            int letterCount = words[i].length();
            int j = i + 1;
            int spaces = 0;

            while (j < n && words[j].length() + 1 + spaces + letterCount <= maxWidth)
            {
                letterCount += words[j].length();
                spaces += 1;
                j++;
            }

            int remainingSlots = maxWidth - letterCount;
            int eachSlotsSpace = spaces == 0 ? 0 : remainingSlots / spaces;
            int extraSlotsSpace = spaces == 0 ? 0 : remainingSlots % spaces;

            if (j == n) // Last line
            {
                eachSlotsSpace = 1;
                extraSlotsSpace = 0;
            }

            ans.push_back(findLine(i, j, eachSlotsSpace, extraSlotsSpace, words, j == n));

            i = j;
        }

        return ans;
    }
};
