package union.mearge_accounts;

import java.security.Key;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.*;

// Your UnionBySize class (looks correct for its functionality)
class UnionBySize {
    List<Integer> size = new ArrayList<>();
    List<Integer> parent = new ArrayList<>();

    public UnionBySize(int n) { // Renamed var1 to n for clarity
        for (int i = 0; i <= n; ++i) { // Initialize for n+1 elements (0 to n)
            this.parent.add(i);
            this.size.add(1);
        }
    }

    // Finds the ultimate parent of an element with path compression
    int findUParent(int i) { // Renamed var1 to i
        if (i == this.parent.get(i)) {
            return i;
        }
        // Path compression: set parent to the ultimate parent directly
        int root = this.findUParent(this.parent.get(i));
        this.parent.set(i, root);
        return root;
    }

    // Unions two sets by size
    void unionBySize(int i, int j) { // Renamed var1, var2 to i, j
        int root_i = this.findUParent(i);
        int root_j = this.findUParent(j);

        if (root_i != root_j) { // Only union if they are in different sets
            if (this.size.get(root_i) < this.size.get(root_j)) {
                this.parent.set(root_i, root_j);
                this.size.set(root_j, this.size.get(root_j) + this.size.get(root_i));
            } else { // root_i size is >= root_j size
                this.parent.set(root_j, root_i);
                this.size.set(root_i, this.size.get(root_i) + this.size.get(root_j));
            }
        }
    }
}


class Solution {
    public List<List<String>> accountsMerge(List<List<String>> accounts) {
        int n = accounts.size();
        // Initialize DSU for 'n' accounts (indices 0 to n-1)
        UnionBySize ds = new UnionBySize(n - 1); // If accounts are 0-indexed, up to n-1

        // Map email to the initial account index it appeared in
        // This is crucial for linking emails to their initial account sets.
        Map<String, Integer> emailToAccountIndexMap = new HashMap<>();

        // Phase 1: Populate map and perform unions
        for (int i = 0; i < n; i++) { // Iterate through each account (account index 'i')
            List<String> currentAccount = accounts.get(i);
            // The first element is the name, so start from j=1 for emails
            for (int j = 1; j < currentAccount.size(); j++) { // Iterate through emails in current account
                String email = currentAccount.get(j);

                if (emailToAccountIndexMap.containsKey(email)) {
                    // If this email has been seen before, it means the current account 'i'
                    // and the previously seen account (emailToAccountIndexMap.get(email))
                    // belong to the same person. Union their sets.
                    ds.unionBySize(i, emailToAccountIndexMap.get(email));
                } else {
                    // If this is the first time we see this email, map it to the current account index 'i'.
                    emailToAccountIndexMap.put(email, i);
                }
            }
        }

        // Phase 2: Group emails by their ultimate parent (merged account)
        // This temporary map will hold: ultimate_parent_index -> List_of_emails_in_that_merged_account
        Map<Integer, List<String>> mergedAccountsMap = new HashMap<>();

        for (Map.Entry<String, Integer> entry : emailToAccountIndexMap.entrySet()) {
            String email = entry.getKey();
            Integer originalAccountIndex = entry.getValue();

            // Find the ultimate parent of the original account index
            int ultimateParent = ds.findUParent(originalAccountIndex);

            // Add the email to the list associated with its ultimate parent
            mergedAccountsMap.computeIfAbsent(ultimateParent, k -> new ArrayList<>()).add(email);
        }

        // Phase 3: Format the result as List<List<String>> and add names
        List<List<String>> result = new ArrayList<>();

        for (Map.Entry<Integer, List<String>> entry : mergedAccountsMap.entrySet()) {
            Integer ultimateParentIndex = entry.getKey(); // This index refers to one of the original accounts
            List<String> emails = entry.getValue();

            // Sort the emails alphabetically as per problem requirement
            Collections.sort(emails);

            // Get the name associated with this merged account.
            // The name is always the first element of the original account that became the parent.
            // Be careful here: accounts.get(ultimateParentIndex).get(0) assumes that the name
            // in the original 'accounts' list at `ultimateParentIndex` is the correct name
            // for the entire merged account. This is a standard assumption in this problem.
            String accountName = accounts.get(ultimateParentIndex).get(0);

            // Create the final list for this merged account: [name, email1, email2, ...]
            List<String> mergedAccountList = new ArrayList<>();
            mergedAccountList.add(accountName);
            mergedAccountList.addAll(emails); // Add all sorted emails

            result.add(mergedAccountList);
        }

        // The problem statement usually implies sorting the final list of accounts based on their first email or name.
        // If not explicitly required, sorting the result list itself might not be needed.
        // However, if the order of merged accounts matters (e.g., for consistent output in online judges):
        // Collections.sort(result, (a, b) -> a.get(0).compareTo(b.get(0))); // Sort by name

        return result;
    }
}



public class MeargeAccounts {
    public static void main(String[] args) {

    }
}


