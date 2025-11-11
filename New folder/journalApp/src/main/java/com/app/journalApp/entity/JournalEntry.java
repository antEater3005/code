package com.app.journalApp.entity;

import java.time.LocalDateTime;

import org.bson.types.ObjectId;
import org.springframework.data.annotation.Id;
import org.springframework.data.mongodb.core.mapping.Document;

import lombok.Getter;
import lombok.NonNull;
import lombok.Setter;

@Getter
@Setter

@Document(collection = "journal_entries")
public class JournalEntry {

    @Id
    private ObjectId _id;
    @NonNull
    private String title;
    private String content;
    private LocalDateTime date;
}
