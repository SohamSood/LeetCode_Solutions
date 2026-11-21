class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string,vector<int>> mp; // ingredients correspoding to this recieps(index);
        // whenever i reach that index just pop back from ingredients correspondingly instead of doing size

        for(int i = 0;i<ingredients.size();i++)  {
            for(string& curr_ingredient: ingredients[i]) {
                mp[curr_ingredient].push_back(i);
            }
        }
        // for (auto& [ingredient, indices] : mp) {
        //     cout << ingredient << " -> ";

        //     for (int idx : indices) {
        //         cout << recipes[idx] << " ";
        //     }

        //     cout << endl;
        // }
        for(int i = 0;i<supplies.size();i++) {
            for(int idx : mp[supplies[i]]) {
                ingredients[idx].pop_back();
                if(ingredients[idx].size() == 0) {
                    supplies.push_back(recipes[idx]);
                }
            }
        }
        // for (auto& [ingredient, indices] : mp) {
        //     cout << ingredient << " -> ";

        //     for (int idx : indices) {
        //         cout << recipes[idx] << " ";
        //     }

        //     cout << endl;
        // }
        vector<string> ans;
        for(int i = 0;i<recipes.size();i++) {
            if(ingredients[i].size() == 0) ans.push_back(recipes[i]);
        }
        return ans;
    }
};