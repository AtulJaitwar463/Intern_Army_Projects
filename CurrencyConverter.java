import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;

public class CurrencyConverter {

    public static void main(String[] args) {
        try {
            // Get user input
            BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
            System.out.print("Enter the amount to convert: ");
            double amount = Double.parseDouble(reader.readLine());

            System.out.print("Enter the source currency code (e.g., USD): ");
            String sourceCurrency = reader.readLine().toUpperCase();

            System.out.print("Enter the target currency code (e.g., EUR): ");
            String targetCurrency = reader.readLine().toUpperCase();

            // Get the conversion rate from an API
            String apiKey = "47e5b2f153bd36610163b238";
            double conversionRate = getConversionRate(apiKey, sourceCurrency, targetCurrency);

            // Calculate and display the converted amount
            double convertedAmount = amount * conversionRate;
            System.out.println(amount + " " + sourceCurrency + " is equal to " + convertedAmount + " " + targetCurrency);

        } catch (Exception e) {
            System.out.println("An error occurred: " + e.getMessage());
        }
    }

    private static double getConversionRate(String apiKey, String sourceCurrency, String targetCurrency) throws Exception {
        String apiUrl = "https://open.er-api.com/v6/latest/" + sourceCurrency + "?apikey=" + apiKey;

        URL url = new URL(apiUrl);
        HttpURLConnection connection = (HttpURLConnection) url.openConnection();
        connection.setRequestMethod("GET");

        BufferedReader reader = new BufferedReader(new InputStreamReader(connection.getInputStream()));
        StringBuilder response = new StringBuilder();
        String line;

        while ((line = reader.readLine()) != null) {
            response.append(line);
        }
        reader.close();

        // Parse the JSON response and extract the conversion rate
        // Note: You may need to use a JSON library for better parsing
        // For simplicity, we'll use substring here
        String jsonResponse = response.toString();
        int start = jsonResponse.indexOf(targetCurrency) + 5;
        int end = jsonResponse.indexOf(",", start);
        String rateSubstring = jsonResponse.substring(start, end);

        return Double.parseDouble(rateSubstring);
    }
}
 
