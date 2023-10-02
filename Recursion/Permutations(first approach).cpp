int return_permutations(string input, string output[])
{
    if(input.empty() || input.length() == 0)
    {
        output[0] = input;
        return 1;
    }
    string smaller_output[1000];

    int smaller_outputSize = return_permutations(input.substr(1), smaller_output);
    char first_char = input[0];
    int k = 0;

    for(int i = 0; i<smaller_outputSize; i++)
    {
        for(int j = 0; j<=smaller_output[i].length(); j++)
        {
            output[k] = smaller_output[i].substr(0, j) + first_char + smaller_output[i].substr(j);
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
