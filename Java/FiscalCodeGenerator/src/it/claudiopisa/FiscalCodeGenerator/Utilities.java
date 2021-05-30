package it.claudiopisa.FiscalCodeGenerator;

@SuppressWarnings("unused")
public class Utilities 
{

	/**
	 * 
	 * @param <b>char c</b>
	 * @return <b>true</b> if <b>c</b> is a wovel
	 * @return <b>false</b> if <b>c</b> is not a wovel
	 * 
	 * The method handles both uppercase and lowercase letters
	 */
	public boolean isConsonant(char c) { 
		return (!isWovel(c));
	}
	
	/**
	 * 
	 * @param <b>char c</b>
	 * @return <b>true</b> if <b>c</b> is a consonant
	 * @return <b>false</b> if <b>c</b> is not a consonant
	 * 
	 * The method handles both uppercase and lowercase letters
	 */
	public boolean isWovel(char c) { 
		return ((c == 'A' || c == 'a') 
			 || (c == 'E' || c == 'e')
			 || (c == 'I' || c == 'i') 
			 || (c == 'O' || c == 'o') 
			 || (c == 'U' || c == 'u')); 
	}
	
	String name;
	String lastName;

	private String setInitials(String line)
	{
		String initials = new String(generateNameInitials(line));

		return initials;
	}
	
	public String getFullNameInitials(String name, String lastName)
	{
		String nameInitials = setInitials(name);
		String lastNameInitials = setInitials(lastName);
			
		return nameInitials.concat(lastNameInitials);
	
	}
	
	
	private String generateNameInitials(String name)
	{
		char nameInitials[] = new char[150];
		int i, j, k, h, count, consonant = 0;
		int state = 3;
		
		for(i = 0; i < name.length(); i++){
			if(checkForConsonant(name.charAt(i)))
				++consonant;
		}

		if(consonant >= 4){
			i = j = consonant = 0;
			while(state > 0){
				if(checkForConsonant(name.charAt(i))){
					if(consonant != 1){
						nameInitials[j++] = name.charAt(i);
						--state; // only if added.
					}
					++consonant; // at each consonant found
				}
				++i; // at each index.
			}
		}
		else{
			for(i = 0, j = 0; i < name.length() && state > 0; i++){
				if(checkForConsonant(name.charAt(i))){
					nameInitials[j++] = name.charAt(i);
					--state;
				}
			}
			if(state > 0){
				for(h = 0, k = j; h < name.length() && state > 0; h++){
					if(checkForVowel(name.charAt(h))){
						nameInitials[k++] = name.charAt(h);
						--state;
					}	
				}
			}
			
		} // end of else
		
		String nameInitials1 = new String(nameInitials);
		
		return nameInitials1;
	} // end of nethod
			
		
	private void generateLastName(String lastName)
	{	
		char lastNameInitials[] = new char[150];
		int i, j, k, h, state;
		state = 3;
		
		for(i = 0, j = 0; i < lastName.length() && state > 0; i++)
			if(checkForConsonant(lastName.charAt(i))){
				lastNameInitials[j++] = lastName.charAt(i);
				--state;
			}
		if(state > 0)
			for(h = 0, k = j; h < lastName.length() && state > 0; h++)
				if(checkForVowel(lastName.charAt(h))){
					lastNameInitials[k++] = lastName.charAt(h);
					--state;
				}
		
	}
	
	
	private boolean checkForConsonant(char ch)
	{
		
		switch(ch){
			case 'B': case 'b':
			case 'C': case 'c':
			case 'D': case 'd':
			case 'F': case 'f':
			case 'G': case 'g':
			case 'H': case 'h':
			case 'L': case 'l':
			case 'M': case 'm':
			case 'N': case 'n':
			case 'P': case 'p':
			case 'Q': case 'q':
			case 'R': case 'r':
			case 'S': case 's':
			case 'T': case 't':
			case 'V': case 'v':
			case 'W': case 'w':
			case 'X': case 'x':
			case 'Z': case 'z':
				return true;
			default:
				return false;
			
		}
		
	}
	
	private boolean checkForVowel(char ch)
	{
		
		switch(ch){
			case 'A': case 'a':
			case 'E': case 'e': 
			case 'I': case 'i': 
			case 'O': case 'o':
			case 'U': case 'u':
				return true;
			default:
				return false;
		}
	
	}
}
