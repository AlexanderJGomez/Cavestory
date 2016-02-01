//
//  utils.h
//  Cavestory
//
//  Created by Alex Gomez on 12/31/15.
//  Copyright (c) 2015 Alex Gomez. All rights reserved.
//

#ifndef __Cavestory__utils__
#define __Cavestory__utils__

#include <string>
#include <vector>

class Utils {
    
public:
    // spllit astrin gtxt everywherea certain character ch
    // if found storing the results in a vector strs
    static unsigned int split(const std::string &txt, std::vector<std::string> &strs, char ch) {
        int pos = txt.find(ch);
        int initialPos = 0;
        strs.clear();
        while (pos != std::string::npos) {
            strs.push_back(txt.substr(initialPos, pos - initialPos + 1));
            initialPos = pos + 1;
            
            pos = txt.find(ch, initialPos);
        }
        ///add the last one
        strs.push_back(txt.substr(initialPos, std::min<int>(pos, txt.size() - (initialPos + 1))));
        
        return strs.size();
        
    }
    
};




#endif /* defined(__Cavestory__utils__) */
