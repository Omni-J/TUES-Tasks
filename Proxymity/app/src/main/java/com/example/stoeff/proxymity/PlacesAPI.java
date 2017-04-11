package com.example.stoeff.proxymity;

import retrofit2.Call;
import retrofit2.http.GET;
import retrofit2.http.Query;

/**
 * Created by stoeff on 28/02/17.
 */

public interface PlacesAPI {

    @GET("https://maps.googleapis.com/maps/api/place/nearbysearch/json")
    public Call<PlacesResponce> getPlacesByLocation(
            @Query("location") String location,
            @Query("key") String key,
            @Query("rankby") String rankby,
            @Query("type") String type);
}

