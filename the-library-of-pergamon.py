import sys

def CONFIG():
    return "shelf.txt"

try:
    with open(CONFIG(), 'r') as config:
        pass

except FileNotFoundError:
    with open(CONFIG(), 'a') as config:
        pass

def AddEntry(EntryName: str):
    with open(CONFIG(), 'r') as config:
        if (EntryName + "\n") not in config.readlines():
            with open(CONFIG(), 'a') as config:
                    config.write(EntryName + '\n')
                    config.write("Status: Pending\n")
                    config.write("Chapter: 0\n")
                    config.write("Page: 0\n")
        else:
            print("Entry already exists!")

def ListEntries():
    with open(CONFIG(), 'r') as config:
        Lines = config.readlines()
        for entry in range(0, len(Lines), 4):
            print(Lines[entry])

def EditEntry(EntryName: str, Property: str, Change):
    with open(CONFIG(), 'r') as config:
        Lines = config.readlines()
        if (EntryName + "\n") in Lines:
            ToEdit = Lines.index(EntryName + "\n")
            with open(CONFIG(), 'w') as config:
                    match Property:
                        case '-c':
                            Lines[ToEdit + 2] = Lines[ToEdit + 2].split(': ')[0] + ': ' + Change + "\n"
                            config.writelines(Lines)
                        case '-p':
                            Lines[ToEdit + 3] = Lines[ToEdit + 3].split(': ')[0] + ': ' + Change + "\n"
                            config.writelines(Lines)
        else:
            print("Not found.")

if __name__ == "__main__":

    Argument = sys.argv[1]

    match Argument:

        case '-a' | '--add':
            AddEntry(Entry := sys.argv[2])

        case '-l' | '--list':
            ListEntries()

        case '-e' | '--edit':
            EditEntry(Entry := sys.argv[2], Property := sys.argv[3], Change := sys.argv[4])

