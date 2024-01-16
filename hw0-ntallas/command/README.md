0-1. Στο επίπεδο 0 η μόνη δυσκολία που αντιμετώπισα ήταν η αλλαγή του port μέσω του terminal. Μέσω ενός απλού ls εμφανιστηκε ενα αρχείο ονόματι readme το οποίο άνοιξα μεσω του nano. Ο κωδικός που είχε ήταν ο κωδικός του επομένου bndit (1). Συνδέθηκα στο bandit 1 χρησιμοποιώντας ssh bandit1@bandit.labs.overthewire.org -p 2220 και κωδικό τον προαναφερθέντα. 

1-2. Όμοια με 0-1: ls , nano ./- και το αρχείο "-" περιείχε τον κωδικό. , είσοδος με ssh bandit2@bandit.labs.overthewire.org -p 2220 (στα επόμενα βήματα παραλλείπεται για χάρην συντομίας και όπου bandit2 το αντίστοιχο επόμενο bandit πχ bandit3)

2-3. ls , nano ./"spaces in this filename", εμφάνιση κωδικού.

3-4. ls, cd ./inhere, ls δίχως αποτέλεσμα οπότε ls -a και εμφάνιση ενός αρχείου ονόματι ".hidden", cat ./.hidden .

4-5. ls, cd ./inhere, ls με εμφανιση πολλων file(file00,file01...). η είσοδος στο πρώτο εμφάνισε με nano ./"-file00" έδειξε πως ήταν data file , file ./* που εμφάνισε πως μόνο το file07 είχε ascii , cat ./"-file07".

5-6. ls, cd ./inhere, ls , Χρησιμοποιώντας την περιγραφή, τα συνιστώμενα commands και το manual αυτών : find . -readable -size 1033c , cd ./maybehere07 , cat ./.file2 .

6-7. ls , ls -al (Κανένα αποτέλεσμα) , cd / , χρησιμοποιώντας την περιγραφή: find . -group bandit6 -user bandit7 -size 33c  όπου permission denied και για να κρύψω τα errors : 2>/dev/null (google) , nano /var/lib/dpkg/info/bandit7.password.

7-8. ls , nano data.txt , χρήση του ^w command του nano με parameter "millionth".

8-9: ls, αρχικά cat data.txt | uniq -u (γιατί δεν δουλεύει;) και έπειτα sort data.txt | uniq -u.

9-10. ls, sort data.txt | grep === .

10-11. ls , nano data.txt , Στην περιγραφή λέει πως χρησιμοποιείται base64 οπότε με έναν base64 decoder από το ίντερνετ (πχ base64decode.org/) εμφανίζεται ο κωδικός. Εναλλακτικά, χρήση της εντολής : base64 -d data.txt (περιγραφή)
