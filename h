def decode(message_file):
    with open(message_file, 'r') as file:
        lines = file.readlines()

    # Parse the lines into a dictionary {number: word}
    words_dict = {}
    for line in lines:
        number, word = line.split()
        words_dict[int(number)] = word

    # Determine the end of each pyramid row
    pyramid_indices = []
    row = 1
    while len(pyramid_indices) + row <= len(words_dict):
        pyramid_indices.append(sum(range(row + 1)))
        row += 1

    # Extract the words at the pyramid indices
    decoded_message = ' '.join(words_dict[i] for i in pyramid_indices)
    
    return decoded_message
