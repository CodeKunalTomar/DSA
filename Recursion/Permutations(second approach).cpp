
int return_permutations(string input, string output[])
{
    if(input.empty() || input.length() == 0)
    {
        output[0] = input;
        return 1;
    }

    int k = 0;

    for(int i = 0; i<input.length(); i++)
    {
        char first_char = input[i];
        string small_input = input.substr(0, i) + input.substr(i+1);
        string small_output[1000];
        int small_outputSize = return_permutations(small_input, small_output);
        for(int j = 0; j<small_outputSize; j++)
        {
            output[k] = first_char + small_output[j];
            k++;
        }
    }
    return k;

}

int main()
{
    string input;
    cin >> input;

    string output[1000];

    int k = return_permutations(input, output);

    for(int i = 0; i<k; i++)
    {
        cout << output[i] << endl;
    }

}
