package com.example.stoeff.myfourthcheesyapp;

import android.content.Context;
import android.support.v7.widget.RecyclerView;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by stoeff on 21/02/17.
 */

public class StringAdapter extends RecyclerView.Adapter {

    private List<String> strings = new ArrayList<>();

    @Override
    public RecyclerView.ViewHolder onCreateViewHolder(ViewGroup parent, int viewType) {
        Context context = parent.getContext();

        LayoutInflater inflater = LayoutInflater.from(context);

        View children = inflater.inflate(R.layout.layout_list_item, parent, false);

        return new TextVH(children);
    }

    @Override
    public void onBindViewHolder(TextVH holder, int position) {

    }

    @Override
    public int getItemCount() {
        return 0;
    }

    public static class TextVH extends RecyclerView.ViewHolder{

        public TextVH(View itemView) {
            super(itemView);
        }
    }
}
