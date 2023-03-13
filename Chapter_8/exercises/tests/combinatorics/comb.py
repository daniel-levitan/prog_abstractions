def comb(string: str, combinations: set):
    if string:
        combinations.add(string)
        for i, l in enumerate(string):
            comb(string[:i] + string[i + 1:], combinations)
        return combinations

def sumComb(combinations: set, result: set):
    summ = 0
    # print("SET ", combinations)
    if combinations:
        for e in combinations:
            summ += e        
        result.add(summ)
        # print(result)
        for e in combinations:
            rest = combinations - {e}
            # print("REST ", rest)
            sumComb(rest, result)
    return result

def main():
    result = set()
    combinations = {0, 1, 2}
    print(sumComb(combinations, result))    
    


    # Test string
    combinations = comb("ABCD", combinations)
    comb_list = list(combinations)
    comb_list.sort(key=lambda item: (-len(item), item))
    print(len(comb_list))

    

if __name__ == "__main__":
    main()





