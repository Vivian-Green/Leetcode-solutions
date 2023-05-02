char whitespace = ' ';
int charCodeFor0 = (int) '0';
char minus = '-';
char plus = '+';

int isSign(char character){
    return(character == minus || character == plus);
}

int isValidChar(char character){
    int isNumeric = character >= charCodeFor0 & character <= charCodeFor0 + 9;
    if(isNumeric){
        return 1;
    }else if(isSign(character)){
        return 1;
    }
    return 0;
}

int charToDigit(char validCharacter){
    return (int) validCharacter - (int) charCodeFor0;
}

long myAtoi(char * s){
    long clampMin = -pow(2, 31);
    long clampMax = pow(2, 31)-1;

    int sLen = strlen(s);
    long out = 0;

    long isNegative = -1;
    int hasSign = 0;
    int hasNum = 0;
    int hasZero = 0;

    int thisChar = 0;
    int isLeadingZero = 0;
    int isLeadingSpace = 0;
    int startedReading = 0;

    //for each char
    for(int i = 0; i < sLen; i++){
        thisChar = s[i];
        isLeadingZero = charToDigit(thisChar) == 0 && hasNum == 0;
        isLeadingSpace = (thisChar == ' ') && hasNum == 0;
        startedReading = hasSign == 1 || hasZero == 1 || hasNum == 1;


        if(isValidChar(thisChar) == 1){
            //leading chars         
            if(isLeadingZero){
                hasZero = 1;
                continue;
            }
            if(isLeadingSpace){
                continue;
            }

            //signs
            if(isSign(thisChar)){
                if(startedReading == 1){
                    break;
                }else if(thisChar == minus){
                    isNegative *= -1L;
                }
                hasSign = 1;
            }else{
                //numbers
                hasNum = 1;

                //Lshift, then add digit
                out *= 10L;
                out += (long) charToDigit(thisChar);

                if((long) out > clampMax){
                    //number outside of clamp, send min/max
                    if(isNegative > 0){
                        return clampMin;
                    }else{
                        return clampMax;
                    }
                }
            }
        }else if(thisChar != ' '){
            //break on weird characters that aren't spaces
            break;
        }else if(startedReading == 1){
            //break on spaces in the middle fo words
            break;
        }
    }

    //handle regular negative numbers if applicable
    if(isNegative > 0){
        out *= -1;
    }

    return out;
}