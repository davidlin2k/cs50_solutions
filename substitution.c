#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

bool validate(string key);
char find_cipher_char(string key, char letter);

int main(int argc, string argv[])
{
    //check if the command line argument is valid
    if (argc == 2)
    {
        //check if the given cipher key is valid.
        if (validate(argv[1]))
        {
            //get the plain text from user and evaluate the character count.
            string plaintext = get_string("plaintext: ");
            int charcount = (int) strlen(plaintext);
            
            //create the variable and we will add the encrypted letters through the loop. The size is 
            //the character count + 1 because we need a null at the end of the string.
            char ciphertext[charcount + 1];
            
            //iterate through each character in the plain text.
            for (int i = 0; i < charcount; i++)
            {
                //check if the letter in the plain text is lower case.
                bool is_lower = islower(plaintext[i]);
                //get the cipher char through the function.
                char temp = find_cipher_char(argv[1], plaintext[i]);
                //if the original char is a lower case, we want to make sure the returned char from the function is a lower case too.
                if (is_lower)
                {
                    ciphertext[i] = tolower(temp);
                }
                else
                {
                    ciphertext[i] = toupper(temp);
                }
            }
            //add the null at the end of the string.
            ciphertext[charcount] = '\0';
            printf("ciphertext: %s\n", ciphertext);
            return 0;
        }
        else
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
    }
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
}

bool validate(string key)
{
    //validate the length of the key
    if (strlen(key) == 26)
    {
        for (int i = 0; i < 26; i++)
        {
            //if it's not a letter, exit the function and return false.
            if (!isalpha(key[i]))
            {
                return false;
            }
            //iterate through the characters after the current character and check for duplicates.
            for (int j = i + 1; j < 26; j++)
            {
                //if a duplicate letter is found, exit the function and return false;
                if (key[i] == key[j])
                {
                    return false;
                }
            }
        }
        //after validation, return true.
        return true;
    }
    else
    {
        return false;
    }
}

char find_cipher_char(string key, char letter)
{
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    //iterate through the alphabet and get the index of the letter in the alphabet, then return the corrisponding cipher char in the given key.
    for (int i = 0, n = strlen(alphabet); i < n; i++)
    {
        if (toupper(letter) == alphabet[i])
        {
            return key[i];
        }
    }
    //if the char is not a letter, return the original char.
    return letter;
}
