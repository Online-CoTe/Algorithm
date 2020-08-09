
bool validPalindrome(char * s){
    int en = 0, st = 0;;
    for(en = 0; s[en] != 0; en++){}
    en--;
    bool  wrong = 0;
    
    while(st < en){
        if(s[st] != s[en]){
            wrong = 1; break;
        }
        st++;
        en--;
    }
    
    if(wrong){
        int st1 = st, en1 = en - 1;
        bool flag1 = 0;
        while(st1 < en1){
            if(s[st1] != s[en1]) {flag1 = 1; break;}
            st1++;
            en1--;
        }
        
        bool flag2 = 0;
        st1 = st + 1, en1 = en;
           while(st1 < en1){
            if(s[st1] != s[en1]) {flag2 = 1; break;}
            st1++;
            en1--;
        }
    
        if(flag1 && flag2) return 0;
        else return 1;
    }
    else return 1;
    
}
