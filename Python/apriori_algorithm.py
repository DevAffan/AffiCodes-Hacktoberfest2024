def apriori(transactions, min_support):
    def get_support(itemset, transactions):            # It calculates how many transactions contain the itemset. If the itemset is a subset of the transaction, it increments the count.
        count = 0
        for transaction in transactions:
            if itemset.issubset(transaction):
                count += 1
        return count

    def generate_candidates(prev_freq_itemsets, k):                 # This function generates candidate itemsets of size k. It takes frequent itemsets of size k-1 and merges them to generate possible k-itemsets.
        candidates = set()
        prev_freq_itemsets = list(prev_freq_itemsets)
        for i in range(len(prev_freq_itemsets)):
            for j in range(i + 1, len(prev_freq_itemsets)):
                candidate = prev_freq_itemsets[i].union(prev_freq_itemsets[j])
                if len(candidate) == k:
                    candidates.add(candidate)
        return candidates

    def filter_candidates(candidates, transactions, min_support):             # Filters out candidate itemsets that don't meet the minimum support threshold.
        freq_itemsets = {}
        for candidate in candidates:
            support = get_support(candidate, transactions)
            if support >= min_support:
                freq_itemsets[frozenset(candidate)] = support
        return freq_itemsets

    # Convert transactions to list of sets for easier manipulation
    transactions = list(map(set, transactions))

    # Step 1: Generate frequent 1-itemsets
    # Create a set of unique items
    items = set()
    for transaction in transactions:
        for item in transaction:
            items.add(item)

    # Create a list of single-item sets (candidates)
    candidates = [{item} for item in items]
    freq_itemsets = filter_candidates(candidates, transactions, min_support)
    k = 2
    all_freq_itemsets = freq_itemsets.copy()

    # Step 2: Generate frequent k-itemsets
    while freq_itemsets:
        candidates = generate_candidates(freq_itemsets.keys(), k)
        freq_itemsets = filter_candidates(candidates, transactions, min_support)
        all_freq_itemsets.update(freq_itemsets)
        k += 1

    return all_freq_itemsets

# Example usage:
transactions = [
    ['milk', 'bread', 'butter'],
    ['beer', 'bread'],
    ['milk', 'bread', 'beer'],
    ['milk', 'butter'],
    ['beer', 'butter'],
]
min_support = 2
freq_itemsets = apriori(transactions, min_support)

for itemset, support in freq_itemsets.items():
    print(f'Itemset: {set(itemset)}, Support: {support}')