package com.example.stoeff.proxymity;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;

import com.fasterxml.jackson.databind.DeserializationFeature;
import com.fasterxml.jackson.databind.ObjectMapper;

import retrofit.converter.JacksonConverter;
import retrofit2.Call;
import retrofit2.Callback;
import retrofit2.Response;
import retrofit2.Retrofit;
import retrofit2.converter.jackson.JacksonConverterFactory;

public class MainActivity extends AppCompatActivity {

    private static final String TAG = "MainActivity";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);


        ObjectMapper objectMapper = new ObjectMapper();
        objectMapper.configure(DeserializationFeature.FAIL_ON_UNKNOWN_PROPERTIES);

        Retrofit retrofit = new Retrofit.Builder()
                .baseUrl("https://maps.googleapis.com/")
                .addConverterFactory(JacksonConverterFactory.create(objectMapper))
                .build();

        PlacesAPI placeAPI = retrofit.create(PlacesAPI.class);

        String location = "AIzaSyCArpbC1ta_wDibIsNmHdDdgYN_kgVICSY";
        String key = "AIzaSyCArpbC1ta_wDibIsNmHdDdgYN_kgVICSY";
        String rankBy = "distance";
        String type = "bar";

        Call<PlacesResponce> request = placeAPI.getPlacesByLocation(location, key, rankBy, type);

        request.enqueue(new Callback<PlacesResponce>() {
            @Override
            public void onResponse(Call<PlacesResponce> call, Response<PlacesResponce> response) {
                if(response.isSuccessful()){
                    PlacesResponce responceBody = response.body();
                    Log.d();
                }                
            }

            @Override
            public void onFailure(Call<PlacesResponce> call, Throwable t) {

            }
        });
    }


    // AIzaSyCArpbC1ta_wDibIsNmHdDdgYN_kgVICSY
}
