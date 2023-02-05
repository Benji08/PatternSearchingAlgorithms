//std::vector<int> Nsearch(char* pat, char* txt)
//{
//    std::vector<int> index;
//    int pat_length = strlen(pat);
//    int txt_length = strlen(txt);
//    for (int i = 0; i <= txt_length - pat_length; i++) {
//        int j;
//        for (j = 0; j < pat_length; j++)
//            if (txt[i + j] != pat[j])
//                break;
//        if (j == pat_length)
//            index.push_back(i);
//    }
//    return index;
//}

//std::vector<int> KMPSearch(char* pat, char* txt)
//{
//    std::vector<int> index;
//    int pat_length = strlen(pat);
//    int txt_length = strlen(txt);
//    int lps[pat_length];
//
//    computeLPSArray(pat, pat_length, lps);
//
//    int i = 0;
//    int j = 0;
//    while (i < txt_length) {
//        if (pat[j] == txt[i]) {
//            j++;
//            i++;
//        }
//
//        if (j == pat_length) {
//            index.push_back(i - j);
//            j = lps[j - 1];
//        }
//
//        else if (i < txt_length && pat[j] != txt[i]) {
//
//            if (j != 0)
//                j = lps[j - 1];
//            else
//                i = i + 1;
//        }
//    }
//    return index;
//}
//
//std::vector<int> KRsearch(char pat[], char txt[], int q)
// {
//    std::vector<int> index;
//    int pat_length = strlen(pat);
//    int txt_length = strlen(txt);
//    int i, j;
//    int hash_pat_valu = 0;
//    int hash_txt_valu = 0;
//    int h = 1;
//
//    for (i = 0; i < pat_length - 1; i++)
//        h = (h * d) % q;
//
//    for (i = 0; i < pat_length; i++)
//    {
//        hash_pat_valu = (d * hash_pat_valu + pat[i]) % q;
//        hash_txt_valu = (d * hash_txt_valu + txt[i]) % q;
//    }
//
//    for (i = 0; i <= txt_length - pat_length; i++)
//    {
//
//        if ( hash_pat_valu == hash_txt_valu )
//        {
//            bool flag = true;
//            for (j = 0; j < pat_length; j++)
//            {
//                if (txt[i+j] != pat[j])
//                {
//                    flag = false;
//                    break;
//                }
//                if(flag)
//                    std::cout<<i<<" ";
//
//            }
//
//            if (j == pat_length){
//                index.push_back(i);
//            }
//        }
//
//        if ( i < txt_length-pat_length )
//        {
//            hash_txt_valu = (d*(hash_txt_valu - txt[i]*h) + txt[i+pat_length])%q;
//
//            if (hash_txt_valu < 0)
//                hash_txt_valu = (hash_txt_valu + q);
//        }
//    }
//    return index;
//}

// hash function prototype

//template <typename CharType>
//int hash(CharType& object, int pat_length, int q){
//    int hashed_value = 1;
//    for(int i=0; i<pat_length; i++){
//        hashed_value = (hashed_value * d) % q;
//    }
//    return hashed_value;
//}
