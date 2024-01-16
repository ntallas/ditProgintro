Mirror

Η συνάρτηση main δέχεται το εύρος των αριθμών για το οποίο ελέγχεται ποιοι οι αριθμοί του είναι τέλεια τετράγωνα. Αντί όμως να ελέγχονται όλοι οι αριθμοί, ελέγχονται μόνο τα τέλεια τετράγωνα του σωσμένου εύρους τα οποία είναι οι τετραγωνισμένοι αριθμοί ανάμεσα στις ρίζες του εύρους. Έστω η ρίζα του τέλειου τετραγώνου αριθμός x > 0, κάτω όριο = low και άνω όριο = high. Αν  x<sqrt(low) => x^2<low , Απορρίπτεται. Αν x>sqrt(high) => x^2 > high, απορρίπτεται. Αρα, low<x<high.

Η isPrime ελέγχει αν ο αριθμός είναι πρώτος με βάση αν διαιρείται από το δυο έως την ρίζα του, βάσει το :  Έστω αριθμός n όχι πρώτος, δηλαδή 
n = a*b με a <= b. Συνεπάγεται a*a <= a*b = n
Αρα, ο έλεγχος μέχρι την ρίζα αρκεί.


Η συνάρτηση isSquare ελέγχει αν ο αριθμός είναι τέλειο τετράγωνο με βάση το αν η ρίζα του είναι ακέραια (floor(ρίζας) = ceiling(ρίζας)) και χρησιμοποιείται μόνο για τα κάτοπτρα των αριθμών που παράγονται από την main.

Η συνάρτηση mirror δέχεται ό,τι αριθμό και επιστρέφει το κάτοπτρο του. 


Η isNotPalindromic δέχεται έναν αριθμό, βρίσκει το κάτοπτρο χρησιμοποιώντας την mirror και ελέγχει αν ο αριθμός και το κάτοπτρο είναι ίδιοι.


Τέλος, η everythingChecker ελέγχει μέσω κλήσεων των προαναφερθέντων συναντήσεων εάν ο αριθμός που δέχτηκε είναι κατοπτρικο πρώτο τετράγωνο (ΚΠΤ).

Για την ταχύτερη εκτέλεση του προγράμματος χρησιμοποιήθηκαν κάποιες μαθηματικές ιδιότητες των ΚΠΤ.
Πιο συγκεκριμένα, αφού οι ρίζες είναι πρώτες δεν μπορούν να τελειώνουν σε ζυγούς αριθμους αρα θα τελειώνουν σε:
1,3,5,7,9. Οι αριθμοί που τελειώνουν σε 5 είναι πολλαπλάσια του πέντε (και επομένως όχι πρώτοι) αρα εξαιρούνται.
Κοιτώντας τα τετράγωνα τους :
```1^2 τελειώνει σε 1
3^2 τελειώνει σε 1
7^2 τελειώνει σε 9
9^2 τελειώνει σε 1
```

Επομένως τα κπτ θα τελειώνουν αναγκαστικά σε ένα ή εννέα και άρα ο αριθμός που θα ελέγχεται mod 10 θα πρέπει να ισούται με ένα ή εννέα. 

Επιπλέων, οι αριθμοί αν αντιστραφούν θα πρέπει να αρχίζουν με ένα η εννιά. Δηλαδή οι ρίζες με 1,3,7,9. Για τους αριθμούς 7 και 9 αυτό είναι αδύνατο διότι όταν τετραγωνίζονται έχουν κρατουμενο (υπερβαίνουν την θέση του ψηφίου τους) και επομένως ο αριθμός δεν μπορεί να αρχίζει με επτά η εννιά (θα αρχίζει με το εκάστοτε κρατούμενο). Αρα οι αριθμοί που μένουν για να τελειώνουν οι ρίζες είναι 1 ή 3 και άρα ρίζα mod 10 = 1 ή 3. 